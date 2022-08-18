#include "main.h"
/**
 */
int execut(char **list_token, char *path)
{
	pid_t pidC;
	int status;

	pidC = fork();

	if (pidC == -1)
	{
		perror("Creation of a child process was unsuccessful!");
		return (-1);
	}
	if (pidC == 0)
	{
		if (execve(path, list_token, environ) == -1)
			return (-1);
	}

	wait(&status);

	return (status);
}
