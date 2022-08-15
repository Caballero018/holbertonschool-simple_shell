#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

extern char **environ;

typedef struct built_in
{
	char *key;
	int (*f)();
} op_t;

char *get_command(void);
char **tk_cm(char *comand, char *delim);
int count_word(char *strn);
int (*get_built_in(char *s))(void);
int exit_func(void);
int env_func(void);
void check_built_in(int (*f)(), char **buffer, char *command);

#endif /* MAIN_H */
