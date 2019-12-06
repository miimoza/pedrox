#include "grammar.h"
#include "utils.h"

#include <stdlib.h>
#include <string.h>

char *getNextWord(char *word, char *db_path)
{
	char path[4096] = "";
	strcat(path, db_path);
	strcat(path, "/");
	strcat(path, word);

	char **words = parseFile(path);
	if (!*words)
		return NULL;

	size_t size = 1;
	for (; *(words + size); size++);

	return words[(int)(rand() % size)];
}
