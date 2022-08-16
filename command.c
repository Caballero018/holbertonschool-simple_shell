#include "main.h"

/**
 * get_command - is the getline of the shell
 * Return: in the part of EOF return the buffer
 */
char *get_command(void)
{
	char *buffer = NULL;
	size_t size = 0;
	int lenght = 0;

	lenght = getline(&buffer, &size, stdin);
	if (lenght == EOF)
	{
		free(buffer);
		exit(0);
	}
	return (buffer);
}
