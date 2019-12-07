#include "utils.h"

#include <stdlib.h>
#include <stdio.h>

char **parseFile(char *file_path)
{
	FILE *file = fopen(file_path, "r");

	if (!file)
	{
		char **array = malloc(sizeof(char *));
		array[0] = NULL;
		return array;
	}

	char *c = malloc(1);
	while (fread(c, sizeof (char), 1, file)
		   && (*c == ' ' || *c == '\n' || *c == '\t' || *c == '/'))
		   {puts("hey");}
	free(c);
	fseek(file, -1, SEEK_CUR);

	char **array = malloc(sizeof(char *));
	int pos = 1;
	size_t size = 1;

	char *buffer = malloc(sizeof (char));
	int b = 1;
	while (fread(buffer + size - 1, sizeof (char), 1, file))
	{
		if (buffer[size - 1] == ' ' || buffer[size - 1] == '\n'
			|| buffer[size - 1] == '\t' || buffer[size - 1] == '/')
		{
			if (b == 0) continue;
			b = 0;
			// Add Null byte at the end of the word
			buffer[size - 1] = '\0';
			array[pos - 1] = buffer;

			pos++;
			array = realloc(array, sizeof(char *) * pos);

			buffer = malloc(sizeof(char));
			size = 1;
		}
		else
		{
			b = 1;
			size++;
			buffer = realloc(buffer, sizeof(char) * size);
		}
	}

	array[pos - 1] = NULL;

	fclose(file);

	return array;
}
