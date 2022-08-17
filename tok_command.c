#include "main.h"
/**
 * count_word - count a word in the string
 * @strn: is a pointer of the incoming string
 * Return: the number of words
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

/**
 */
void free_tokens(char **token)
{
	int i = 0;

	while (token[i] != NULL)
	{
		free(token[i]);
		i++;
	}
	free(token);
}

/**
 * **tk_cm - is the tokenize of the line
 * @comand: is a pointer the command received
 * @delim: is a pointer to the delimiter of the tokenize
 * Return: 0 for free, and return the result of the tokenize
 */
char **tk_cm(char *comand, char *delim)
{
	char **token = NULL;
	int i, word = 0;

	word = count_word(comand);

	token = calloc((word + 1), sizeof(char *));
	if (token == NULL)
	{
		return (NULL);
	}
	token[0] = strtok(comand, delim);
	if (token[0] == NULL)
	{
		free(token);
		return (NULL);
	}
	for (i = 1; i < word + 1; i++)
		token[i] = strtok(NULL, delim);
	return (token);
}
