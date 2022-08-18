#include "main.h"
/**
 * error_input - deasa
 *
 * @err_no: erres
 * @copy: dsf
 */
void error_input(char *copy)
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

	strcat(msj_error, ": not found\n");
	length = strlen(msj_error);
	write(1, msj_error, (length + 1));
	STATUS = 32512;

	free(msj_error);
}
