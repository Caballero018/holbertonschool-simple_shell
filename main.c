#include "main.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
	char *pront = "(╬ ಠ益ಠ): ", *line = NULL, *argv[] = {"/bin/ls", NULL};
	size_t line_size = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("%s", pront);

		getline(&line, &line_size, stdin);

		if (execve(argv[0], argv, NULL) == -1)
                                printf("Error:");
                        printf("After execve\n");

		if (!isatty(STDIN_FILENO))
			break;
	}
	return (EXIT_SUCCESS);
}
