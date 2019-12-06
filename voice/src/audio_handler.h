#ifndef AUDIO_HANDLER_H
#define AUDIO_HANDLER_H

#include <portaudio.h>
#include <sndfile.h>
#include <stddef.h>

#define FRAME_PER_BUFFER 512
#define SLEEP_TIME 64

struct callback_data
{
    SNDFILE* file;
    SF_INFO info;
};

struct sound
{
    PaStream* stream;
    struct callback_data* data;
};

void init_audio();
struct sound* load_sound(char* file);
void play_sound(struct sound** sound_bank, size_t index);
struct sound** init_sound_bank();
int add_sound_to_bank(struct sound** sound_bank, struct sound* sound);
void clean_sound_bank(struct sound** sound_bank);
void clean_audio();

int callback(const void* input, void* output, unsigned long frameCount,
             const PaStreamCallbackTimeInfo* timeInfo,
             PaStreamCallbackFlags statusFlags, void* userData);

#endif /* AUDIO_HANDLER_H */
