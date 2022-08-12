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
		if (isatty(1))
			printf("%s", pront);

		if (!isatty(1))
			break;
		getline(&line, &line_size, stdin);
		printf("la línea leida es: %s\n", line);

	}
	return (0);
}
