#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

char *parse_command(char *command);
int add_command_to_history(char *command); /* use linked list*/
void get_last_command();		   /* get last command */
void execute_buitin_cmd(char *command);
void execute_ext_cmd(command);
void print_error(char *err_message);

/* BUILTIN COMMANDS */

int cd();
int help();
int env();
int unsetenv();
int setenv();
int history();
#endif