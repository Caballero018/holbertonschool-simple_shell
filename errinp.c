#include "main.h"
/**
 */
void error_input(int err_no, char *copy)
{
	char *msj_error;
	int length = 0;

	msj_error = malloc((sizeof(char) * strlen(copy)) + 9);
	if (msj_error == NULL)
	{
		free(msj_error);
		return;
	}
	strcat(msj_error, "./hsh: ");
	strcat(msj_error, "1");
	strcat(msj_error, ": ");
	strcat(msj_error, copy);

	if (err_no == 14)
	{
		strcat(msj_error, ": not found\n");
		length = strlen(msj_error);
		write(1, msj_error, (length + 1));
	}
	else
		perror(msj_error);

	free(msj_error);
}
