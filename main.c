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
	pid_t id;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("%s", pront);

		getline(&line, &line_size, stdin);

		id = fork();
		if (id == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
				perror("Error:");
			printf("after excue\n");
		}
		wait(NULL);
		if (!isatty(STDIN_FILENO))
			break;
	}
	return (EXIT_SUCCESS);
}
