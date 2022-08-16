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
char *_getenv(void);
char *_path_dir(char *comd);
void error_input(int err_no, char *copy);
int execut(char **list_token, char *path);

#endif /* MAIN_H */
