#include "audio_handler.h"

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "ealloc.h"
#include "error.h"

void init_audio()
{
    // Close stderr to hide Pa_Initialize debug print
    int stderr_copy = dup(STDERR_FILENO);
    fclose(stderr);

    PaError error = Pa_Initialize();

    // Reopen stderr
    dup2(stderr_copy, STDERR_FILENO);
    close(stderr_copy);

    handle_audio_lib_error(error, paNoError);
}

struct sound* load_sound(char* file)
{
    struct sound* sound = emalloc(sizeof(struct sound));
    struct callback_data* data = emalloc(sizeof(struct callback_data));
    PaStream* stream;

    data->file = sf_open(file, SFM_READ, &(data->info));
    handle_file_system_error(sf_error(data->file), SF_ERR_NO_ERROR);

    PaError error = Pa_OpenDefaultStream(&stream,
                                         0, // NO INPUT
                                         data->info.channels, // STEREO OUT
                                         paFloat32, // FLOATING POINT
                                         data->info.samplerate,
                                         FRAME_PER_BUFFER, callback, data);

    handle_audio_lib_error(error, paNoError);

    sound->data = data;
    sound->stream = stream;

    return sound;
}

void play_sound(struct sound** sound_bank, size_t index)
{
    PaStream* stream = sound_bank[index]->stream;

    PaError error = Pa_StartStream(stream);
    handle_audio_lib_error(error, paNoError);

    printf("[I] Playing");
    while (Pa_IsStreamActive(stream))
    {
        printf(".");
        fflush(stdout);
        Pa_Sleep(SLEEP_TIME);
    }
    printf("\n");
}

struct sound** init_sound_bank()
{
    struct sound** sound_bank = emalloc(sizeof(struct sound*));
    *sound_bank = NULL;
    return sound_bank;
}

int add_sound_to_bank(struct sound** sound_bank, struct sound* sound)
{
    size_t index = 0;
    while (sound_bank[index])
        index++;
    sound_bank[index] = sound;
    sound_bank = erealloc(sound_bank, sizeof(struct sound*) * (index + 1));

    sound_bank[index + 1] = NULL;

    return index;
}

void clean_sound_bank(struct sound** sound_bank)
{
    for (; sound_bank; sound_bank++)
    {
        sf_close(sound_bank[0]->data->file);
        PaError error = Pa_CloseStream(sound_bank[0]->stream);
        handle_audio_lib_error(error, paNoError);
        free(sound_bank[0]->data);
    }

    free(sound_bank);
}

void clean_audio()
{
    PaError error = Pa_Terminate();
    handle_audio_lib_error(error, paNoError);
}

int callback(__attribute__((unused)) const void* input, void* output,
             unsigned long frameCount,
             __attribute__((unused)) const PaStreamCallbackTimeInfo* timeInfo,
             __attribute__((unused)) PaStreamCallbackFlags statusFlags,
             void* userData)
{
    float* out;
    struct callback_data* p_data = (struct callback_data*)userData;
    unsigned long num_read;

    out = (float*)output;
    p_data = (struct callback_data*)userData;

    /* clear output buffer */
    memset(out, 0, sizeof(float) * frameCount * p_data->info.channels);

    /* read directly into output buffer */
    num_read =
        sf_read_float(p_data->file, out, frameCount * p_data->info.channels);

    /*  If we couldn't read a full frameCount of samples we've reached EOF */
    if (num_read < frameCount)
        return paComplete;

    return paContinue;
}
