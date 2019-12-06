CC=clang
CFLAGS=-g -Wall -Wextra -pedantic -std=c11 -lportaudio -lsndfile
SRC=src/voice.c src/audio_handler.c src/error.c src/ealloc.c
BIN=M1-VOICE

all:
	$(CC) $(CFLAGS) $(SRC) -o $(BIN)

clean:
	$(RM) src/*.o $(BIN)
