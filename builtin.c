#include "main.h"

/**
 * cd - changes the current working directory
 * Return: 0 on success, 1 on failure
 */
int cd()
{
	printf("Changed Directories.\n");
	return (0);
}

int history()
{
	return (0);
}

int env()
{
	return (0);
}

int setenv()
{
	return (0);
}

int unsetenv()
{
	return (0);
}

int help()
{
	return (0);
}

int execute_ext_cmd(char *command)
{
	// use execve to find program and execute it.
	// make sure to fork and run it in a new process

	// if not found, throw error
	// ! We will
	return (-1);
}
