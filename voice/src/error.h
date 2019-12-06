#ifndef ERROR_H
#define ERROR_H

#define NO_ERROR 0
#define PROGRAM_ERROR 1
#define MEMORY_ERROR 2
#define FILE_SYSTEM_ERROR 4
#define AUDIO_LIB_ERROR 3

void handle_audio_lib_error(unsigned int error, unsigned int noerror);
void handle_file_system_error(unsigned int error, unsigned int noerror);

#endif /* ERROR_H */
