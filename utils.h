#ifndef UTILS_H
#define UTILS_H

/* Constants */
#define DELIMS " ,.!><|&;\"'\n\t\r"
#define MAX_ARGC 10

#include "main.h"

char **parse_command(char *command);
void print_error(char *argVector, int count, char *command);
int exec_command(char **command);
int execute_ext_cmd(char *command, char **args);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

#endif
