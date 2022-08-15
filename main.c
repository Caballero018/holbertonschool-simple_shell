#include "main.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
	int (*func)();
	char *pront = "(╬ ಠ益ಠ): ", *command = NULL, **list_token = NULL;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("%s", pront);
		command = get_command();
		if (command == NULL)
			continue;
		list_token = tk_cm(command, " \n\t");
		func = get_built_in(list_token[0]);
		check_built_in(func, list_token, command);

		if (!isatty(STDIN_FILENO))
			break;
	}
	return (EXIT_SUCCESS);
}
