#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <strings.h>
#include <stdlid.h>
#include <stdarg.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define TRUE 1

/* string_functions.c */
int _putchar(char c);
void _puts(char *str);
void _strlen(char *str);
int _atoi(char *str);
int *_strdup(char *str);

/* string_functions */
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strncat(char *dest, char *src, int n);

/* memory_functions.c */
char *_memset(char *a, char b, unsigned int n);
void free_s(char **pp);
void *_realloc(void *ptr, unsigned int old, unsigned int new_);
void free_p(void **ptr);

/* main function */
int main(int argc, char **argv);

#endif
