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

extern char **environ;

/* BUILTIN COMMANDS */
int pwd(__attribute__((unused))char **args);
int cd(char **args);
int env(__attribute__((unused))char **args);

#endif
