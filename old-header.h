// #ifndef OLD_HEADER_H
// #define OLD_HEADER_H

// #include <stdio.h>
// #include <string.h>
// #include <unistd.h>
// #include <stdlib.h>
// #include <stddef.h>
// #include <sys/types.h>
// #include <sys/wait.h>

// #include "utils.h"

// #define PATH_MAX 260

// extern char **environ;

// /* BUILTIN COMMANDS */
// int pwd(__attribute__((unused)) char **args);
// int cd(char **args);
// int env(__attribute__((unused)) char **args);

// /* Constants */
// #define DELIMS " ,.!><|&;\"'\n\t\r"
// #define MAX_ARGC 10

// #include "main.h"

// char **parse_command(char *command);
// void print_error(char *argVector, int count, char *command);
// int exec_command(char **command);
// int execute_ext_cmd(char *command, char **args);
// void free_double_ptr(char ***cmds);
// void free_ptr(char **command);

// #endif
