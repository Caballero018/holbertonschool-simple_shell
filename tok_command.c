#include "main.h"

/**
 *
 */
int count_word(char *strn)
{
	int count = 0;
	int word = 0;

	while (*strn)
	{
		if (*strn == ' ' || *strn == '\n' || *strn == '\t' || *strn == '='
				|| *strn == ':')
			count = 0;

		else if (count == 0)
		{
			count = 1;
			word++;
		}
		strn++;
	}
	return (word);
}

char **tk_cm(char *comand, char *delim)
{
	char **token = NULL;
	int i, word = 0;

	word = count_word(comand);

	token = malloc(sizeof(char *) * (word + 1));
	if (token == NULL)
	{
		free(token);
		return(NULL);
	}
	token[0] = strtok(comand, delim);
	if (token[0] == NULL)
	{
		free (token);
		return(NULL);
	}
	for (i = 1; i < word + 1; i++)
		token[i] = strtok(NULL, delim);
	return (token);
}
