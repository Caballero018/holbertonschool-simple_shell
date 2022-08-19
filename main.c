#include "main.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
	int (*func)() = NULL;
	char *pront = "(╬ ಠ益ಠ): ", *command = NULL, **list_token = NULL;
	char *path = NULL;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("%s", pront);
		command = get_command();
		if (command == NULL)
			continue;
		list_token = tk_cm(command, " \n\t");
		if (!list_token)
		{
			free(command);
			continue;
		}
		func = get_built_in(list_token[0]);
		if (func)
		{
			check_built_in(func, list_token, command);
			continue;
		}
		path = path_d(list_token[0]);
		if (path)
		{
			if (execut(list_token, path) == -1)
			{
				error_input(command);
				freess(path, list_token);
				continue;
			}
			freesss(path, list_token, command);
			continue;
		}
		freess(path, list_token);
		if (!isatty(STDIN_FILENO))
			break;
	}
	return (WEXITSTATUS(STATUS));
}
