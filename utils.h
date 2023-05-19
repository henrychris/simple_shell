#ifndef UTILS_H
#define UTILS_H
#define DELIMS " ,.!><|&;\"'\n\t\r"
#define MAX_ARGC 10

#include <sys/types.h>
#include <sys/wait.h>
#include "main.h"

extern char buff[1024];

char **parse_command(char *command);
void print_error(char *argVector, int count, char *command);
int exec_command(char **command);
int execute_ext_cmd(char *command, char **args);
char *getDir(void);

#endif
