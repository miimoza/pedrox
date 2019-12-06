#include "trainer.h"
#include "utils.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int updateDatabase(char *file_path, char *db_path)
{
	char **words = parseFile(file_path);


	while (*words)
	{
		char path[4096] = "";
		strcat(path, db_path);
		strcat(path, "/");
		words[0][strlen(words[0]) - 1] = '\0';
		strcat(path, *words);
		FILE *file = fopen(path, "a+");
		if (!file)
			return 1;

		if (words[1])
		{
			size_t word_size = strlen(words[1]);
			words[1] = realloc(words[1], word_size + 2);
			words[1][word_size + 1] = '\0';
			words[1][word_size] = ' ';
			fwrite(words[1], sizeof(char), strlen(words[1]), file);
		}

		fclose(file);

		words++;
	}

	return 0;
}
