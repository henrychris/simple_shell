#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "utils.h"

#define PATH_MAX 260

int add_command_to_history(char *command); /* use linked list*/
void get_last_command();		   /* get last command */

/* BUILTIN COMMANDS */
int pwd();
int cd(char **args);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
int env();
int history();
#endif
