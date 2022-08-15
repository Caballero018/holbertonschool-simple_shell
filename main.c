#include "main.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
	char *pront = "(╬ ಠ益ಠ): ", *command = NULL, **list_token = NULL;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("%s", pront);
		command = get_command();
		if (command == NULL)
			continue;
		list_token = tk_cm(command, " \n\t");

		if (!isatty(STDIN_FILENO))
			break;
	}
	return (EXIT_SUCCESS);
}
