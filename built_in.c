#include "main.h"

/**
 * exit_func - exit command.
 * Return: 1.
 */
int exit_func(void)
{
	exit(EXIT_SUCCESS);
}

/**
 * env_func - write variable enviromen.
 *
 * Return: 0.
 */
int env_func(void)
{
	int i = 0;

	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (0);
}

/**
 * get_built_in - Selects the correct function, based on the ones
 * set by the user.
 *
 * @s: format.
 * Return: 0
 *
 */
int (*get_built_in(char *s))(void)
{
	int i;
	op_t func[] = {
		{"env", env_func},
		{"exit", exit_func},
		{NULL, NULL}
	};

	for (i = 0; func[i].key != NULL; i++)
		if (strcmp(func[i].key, s) == 0)
			return (func[i].f);
	return (0);
}

/**
 * check_built_in - check built in
 *
 * @f: Function to check.
 * @buffer: Space in memory.
 * @command: Command.
 */
void check_built_in(int (*f)(), char **buffer, char *command)
{
	if (f)
	{
		if (f() == 1)
		{
			free(command);
			free(buffer);
			if (isatty(STDIN_FILENO) != 1)
				exit(127);
		}
	}
}
