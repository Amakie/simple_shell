#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <stddef.h>
#include <sys/stat.h>
#include <signal.h>
#include <limits.h>

#define TRUE 1

extern char **environ;

/* string_functions.c */
int _putchar(char c);
void _puts(char *str);
int _strlen(char *str);
int _atoi(char *str);
char *_strdup(char *str);

/* string_functions */
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strncat(char *dest, char *src, int n);


/* main function */
void prompt(void);
int _error(void);
int main(__attribute((unused))int argc, char **argv);

/* more_functions.c */
char **_tokenizer(char *command, char *delim);
int _exit(char *command, int status, char **args);

#endif
