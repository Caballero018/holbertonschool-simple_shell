#include "main.h"

/**
 * exit_ins - exit command.
 * Return: nothing.
 */
int exit_func(void)
{
	return (1);
}

/**
 * env_ins - write variable enviromen.
 *
 * Return: Always int.
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
 *
 */
void check_built_in(int (*f)(), char **buffer, char *command)
{
	if (f)
		if (f() == 1)
		{
			free(command);
			free(buffer);
			exit(127);
		}
}
