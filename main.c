#include "main.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
	char *pront = "(╬ ಠ益ಠ): ", *command = NULL;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("%s", pront);
		command = get_command();
		if (command == NULL)
			continue;

		if (!isatty(STDIN_FILENO))
			break;
	}
	return (EXIT_SUCCESS);
}
