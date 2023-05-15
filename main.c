#include "main.h"

/**
 * main - main function for the shell
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char **argv)
{
	char *command, path[PATH_MAX];

	command = (char *)malloc(1024 * sizeof(char));
	getcwd(path, sizeof(path));

	if (command == NULL)
	{
		/* print error to stderror */
		return (1);
	}

	while (1)
	{
		printf("$ %s ", path);
		if (fgets(command, 1024, stdin) == NULL)
		{
			/* print error to stderror */
			break;
		}
		/* TODO Trim command input*/
		if (strcmp(command, "exit\n") == 0)
			break;
		/* parse the command here. */
		parse_command(command);
		/* execute the command here.*/
	}
	free(command);
	return (0);
}

/**
 * parse_command - parses the command
 * @command: command to parse
 * Return: void
 */
void parse_command(char *command)
{
	/**
	 * placeholder for splitting command into components
	*/
	const char delimiters[] = " ,.!><|&;\"'";

	char *token = strtok(command, delimiters);
	while (token != NULL)
	{
		printf("Token: %s\n", token);
		token = strtok(NULL, delimiters);
	}
}
