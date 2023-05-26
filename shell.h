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

#endif
