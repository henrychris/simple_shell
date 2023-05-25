#ifndef UTILS_H
#define UTILS_H

#include "main.h"

char **parse_command(char *input);
/* int check_builtins(char **command); */
int exec_command(char **command);

#endif