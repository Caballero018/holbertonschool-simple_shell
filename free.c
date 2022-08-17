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
