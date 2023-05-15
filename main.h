#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

void parse_command(char *command);
int add_command_to_history(char *command); /* use linked list*/
void get_last_command();				   /* get last command */
void execute_buitin_command(char *command);
void execute_command(char *command);
void print_error(char *err_message);

#endif