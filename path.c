#include "main.h"
/**
 */
char *_getenv(void)
{
	int i = 0;
	char *path = NULL;

	while (environ[i])
	{
		if (strncmp(environ[i], "PATH", 4) == 0)
		{
			path = strdup(environ[i]);
			return (path);
		}
		i++;
	}
	return (NULL);
}

/**
 */
char *_path_dir(char *comd)
{
	char *path = NULL, **rout = NULL, *comand = NULL;
	int i = 1;
	struct stat st;

	path = _getenv();
	rout = tk_cm(path, "=:");
	while (rout[i] != NULL)
	{
		if (stat(comd, &st) == 0)
		{
			comand = strdup(comd);
			free(rout);
			free(path);
			return (comand);
		}
		comand = malloc(sizeof(char) * (strlen(rout[i]) + strlen(comd) + 2));
		if (comand == NULL)
		{
			free(comand);
			return (NULL);
		}
		strcpy(comand, rout[i]);
		strcat(comand, "/");
		strcat(comand, comd);
		if (stat(comand, &st) == 0)
		{
			free(path);
			free(rout);
			return (comand);
		}
		free(comand);
		i++;
	}
	free(path);
	free (rout);
	return (NULL);
}