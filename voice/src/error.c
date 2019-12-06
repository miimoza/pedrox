#include "error.h"

#include <err.h>
#include <stdio.h>
#include <stdlib.h>

void handle_audio_lib_error(unsigned int error, unsigned int noerror)
{
    if (error != noerror)
        errx(AUDIO_LIB_ERROR, "[X] Audio lib returned 0x%x\n", error);
}

void handle_file_system_error(unsigned int error, unsigned int noerror)
{
    if (error != noerror)
        errx(FILE_SYSTEM_ERROR, "[X] File system returned 0x%x\n", error);
}
