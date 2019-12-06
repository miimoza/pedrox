CC=clang
CFLAGS=-g -Wall -Wextra -pedantic -std=c11 -lportaudio -lsndfile
SRC=src/main.c src/trainer.c src/grammar.c src/utils.c
BIN=sentance_generator

all:
	$(CC) $(CFLAGS) $(SRC) -o $(BIN)

clean:
	$(RM) *.o $(BIN)
	rm db/*
