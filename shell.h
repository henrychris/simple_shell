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

char **parse_command(char *input);
int exec_command(char **command);
char *find_command(char *command);

/* STRING UTILS */

int _strlen(const char *str);
int _strcmp(const char *str1, const char *str2);
int _strcpy(char *dest, char *src);
char *_strdup(char *s);
char *_strcat(char *dest, const char *src);
void *_memcpy(void *dest, void *src, size_t n);
/* STRING UTILS */
#endif
