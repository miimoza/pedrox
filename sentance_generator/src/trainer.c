#include "trainer.h"
#include "utils.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int updateDatabase(char *file_path, char *db_path)
{
	char **words = parseFile(file_path);

	printf("a: %s\n", words[0]);
	printf("a: %s\n", words[1]);

	while (*words)
	{
		printf("b: %s\n", words[0]);
		printf("b: %s\n", words[1]);

		char path[4096] = "";
		strcat(path, db_path);
		strcat(path, "/");
		// REMOVE THE SPACE AT THE END
		words[0][strlen(words[0])] = '\0';
		strcat(path, *words);

		// IF NEXT WORD EXIST, ADD TO THE FILE <db_path>/<word>
		if (words[1])
		{
			FILE *file = fopen(path, "a+");
			if (!file)
				return 1;

			// USE WORDS[0] MEMORY AS TEMP STORAGE FOR WORDS[1] WITH SPACE
			strcpy(words[0], words[1]);

			size_t word_size = strlen(words[0]);
			words[0] = realloc(words[0], word_size + 2);
			words[0][word_size + 1] = '\0';
			words[0][word_size] = ' ';
			fwrite(words[0], sizeof(char), strlen(words[0]), file);

			fclose(file);
		}


		words++;
	}

	return 0;
}
