#include "main.h"

/**
 *
 *
 */
void freess(char *path, char **list_token)
{
	free(path);
	free_tokens(list_token);
}

void freesss(char *path, char **list_token, char *command)
{
	free(path);
	free(list_token);
	free(command);
}
