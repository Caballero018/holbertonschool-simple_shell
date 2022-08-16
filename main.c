#include "main.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
	int (*func)(), error_numbs;
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
		func = get_built_in(list_token[0]);
		check_built_in(func, list_token, command);
		path = _path_dir(list_token[0]);
		if (path)
		{
			if (execut(list_token, path) == -1)
			{
				error_numbs = errno;
				error_input(error_numbs, command);
				free(path);
				free_tokens(list_token);
				continue;
			}
			else
			{
				free(path);
				free(list_token);
				free(command);
				continue; 
			}
		}
		else
		{
			free(path);
			free_tokens(list_token);
			continue;
		}

		if (!isatty(STDIN_FILENO))
			break;
	}
	return (EXIT_SUCCESS);
}
