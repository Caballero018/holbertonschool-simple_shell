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

