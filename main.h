#ifndef MAIN_H
#define MAIN_H

/* libraries and constants */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/* pointer to array of enviroment variable strings */
extern char **environ;

/* tokenizing functions */
int count_token(char *lineptr, char *delim);
char **tokenize_input(char *lineptr, char *delim);

/* help functions */
char *_strdup(char *src);
int _strlen(char *str);

/* print_error.c */
int _putchar(char c);
void print_str(char *str, int new_line);
void print_error(char *av, char *command);

/* print_num.c */
int print_num(int num);

/* exec_args.c */
void create_child(char **args, char *lineptr, char **av);
void exec_command(char **av, char *lineptr, size_t bufsize);
void free_at_once(int n, ...);

/* builtins.c */
void env_shell(char __attribute__((unused)) *args);
void exit_built(char *lineptr);
void (*get_builtin(char *str))(char *args);
int exec_builtin(char **args, char *lineptr);
int _strcmp(char *s1, char *s2);

/* struct for builtin commands */
/**
 * struct builtin - structure for builtin c commands
 * @cmd: string for command comparison
 * @func: function assigned
 */
typedef struct builtin
{
	char *cmd;
	void (*func)(char *);
} builtin_f;

#endif /* MAIN_H */
