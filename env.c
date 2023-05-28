#include "shell.h"

/**
  * _setenv - set env
  * @cmd1: cmd1
  * @cmd2: cmd2
  * Return: 0 or 1
  */

int _setenv(char *cmd1, char *cmd2)
{
	if (cmd1 == NULL || cmd2 == NULL)
		return (0);
	if (setenv(cmd1, cmd2, 1) != 0)
		_write("Error\n");
	return (0);
}

/**
  * _unsetenv - unset env
  * @cmd1: cmd1
  * Return: 0 or 1
  */
int _unsetenv(char *cmd1)
{
	if (cmd1 == NULL)
		return (0);
	unsetenv(cmd1);
	return (0);
}
