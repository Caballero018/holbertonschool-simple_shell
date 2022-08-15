#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

char *get_command(void);
char **tk_cm(char *comand, char *delim);
int count_word(char *strn);

#endif /* MAIN_H */
