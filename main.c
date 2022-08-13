#include "main.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
	char *pront = "✞𝓓𝖔𝖓✞ $:", *line = NULL;
	size_t line_size = 0;


	while (1)
	{
		if (isatty(STDIN_FILENO))
				printf("%s", pront);

		getline(&line, &line_size, stdin);
                printf("la línea es: %s", line);	

		if (!isatty(STDIN_FILENO))
			break;

	}
	return (EXIT_SUCCESS);
}
