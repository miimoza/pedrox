#include <portaudio.h>
#include <stdio.h>

#include "audio_handler.h"
#include "error.h"

int main()
{
    puts("[1] Init audio");
    init_audio();

    puts("[2] Init Sound Bank");
    struct sound** soundBank = init_sound_bank();

    puts("[3] Load Sound");
    struct sound* do_wav = load_sound("./sounds/do.wav");

    puts("[4] Add Sound to Bank");
    size_t do_index = add_sound_to_bank(soundBank, do_wav);

    puts("[5] Play Sound");
    play_sound(soundBank, do_index);

    puts("[6] Clean Sound Bank");
    clean_sound_bank(soundBank);

    puts("[7] Clean Audio");
    clean_audio();

    return NO_ERROR;
}
