#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

int status;

#define STATUS status

extern char **environ;

/**
 * struct built_in - Struct built_in
 *
 * @key: Variable.
 * @f: Function.
 */
typedef struct built_in
{
	char *key;
	int (*f)();
} op_t;

char *get_command(void);
char **tk_cm(char *comand, char *delim);
void free_tokens(char **token);
int count_word(char *strn);
int (*get_built_in(char *s))(void);
int exit_func(void);
int env_func(void);
void check_built_in(int (*f)(), char **buffer, char *command);
char *path_d(char *comd);
void error_input(char *copy);
int execut(char **list_token, char *path);
char *get_env(void);
void freess(char *path, char **list_token);
void freesss(char *path, char **list_token, char *command);

#endif /* MAIN_H */
