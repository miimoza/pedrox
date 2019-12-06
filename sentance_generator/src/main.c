#include "grammar.h"
#include "trainer.h"
#include "utils.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv)
{

	srand(time(NULL));

	if (argc == 4 && !strcmp(argv[1], "-a"))
	{
		updateDatabase(argv[3], argv[2]);
	}
	else if(argc == 4 && !strcmp(argv[1], "-x"))
	{
		char *word = malloc(4096);
		strcpy(word, argv[3]);
		//fgets(word, 63, stdin);
		//word[strlen(word) - 1] = '\0';

		for (int i = 0; word && i < 20000; i++)
		{
			printf("%s ", word);
			fflush(stdout);
			word = getNextWord(word, argv[2]);
		}

		printf("\n");
	}
	else
	{
		printf("Sentance Generator\n");
		printf("Update the database:  ./sentance_generator -a <database_path> <file>\n");
		printf("Run with first word:  ./sentance_generator -x <database_path> <first_word>\n");
	}

	return 0;
}
