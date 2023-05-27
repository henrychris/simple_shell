#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/wait.h>

#define PATH_MAX 260
#define DELIMS " ,!><|&;\"'\n"
#define MAX_ARGC 10

extern char **environ;

char **parse_command(char *input);
int exec_command(char **command, int count, char *program_name);
char *find_command(char *command);
void _perror(int count, char *command, char *program_name);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

/* STRING UTILS */
int _strlen(const char *str);
int _strcmp(const char *str1, const char *str2);
int _strcpy(char *dest, char *src);
char *_strdup(char *s);
char *_strcat(char *dest, const char *src);
void *_memcpy(void *dest, void *src, size_t n);
/* STRING UTILS */

/* QoL UTILS */
void _write(char *s);
int _putchar(char c);
void write_number(int number);
/* QoL UTILS */
 /* Builtin */
int env(void);
int cd(int count, char *args, char *program_name);
void _perror_cd(int count, char *command, char *program_name);
#endif
