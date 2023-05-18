#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "utils.h"

int add_command_to_history(char *command); /* use linked list*/
void get_last_command();		   /* get last command */
int getline(char **lineptr, size_t *n, FILE *stream);
/* BUILTIN COMMANDS */

int cd();
int help();
int env();
int unsetenv();
int setenv();
int history();
#endif
