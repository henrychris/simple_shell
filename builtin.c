/*
 *#include "main.h"
 *#include "utils.h"
 *
 *
 *int cd(char **args)
 *{
 *	char *dirName = args[1];
 *
 *	if (dirName == NULL)
 *	{
 *		dirName = getenv("HOME");
 *		if (!dirName)
 *			perror("Fail");
 *	}
 *	else if (strcmp(dirName, "-") == 0)
 *	{
 *		dirName = getenv("OLDPWD");
 *		if (!dirName)
 *			perror("Fail");
 *	}
 *	if (chdir(dirName) != 0)
 *		perror("Fail");
 *	else
 *	{
 *		if (setenv("PWD", dirName, 1) != 0)
 *			perror("Fail");
 *	}
 *	return (0);
 *}
 *
 *
 *int env(__attribute__((unused))char **args)
 *{
 *	char **env = environ;
 *
 *	while (*env)
 *	{
 *		write(1, *env, strlen(*env));
 *		write(1, "\n", 1);
 *		env++;
 *	}
 *	return (0);
 *}
 *
 *
 *int pwd(__attribute__((unused))char **args)
 *{
 *	char *buff = malloc(sizeof(char) * PATH_MAX);
 *
 *	if (getcwd(buff, PATH_MAX) == NULL)
 *	{
 *		perror("Error with getcwd() in pwd(void)");
 *		free_ptr(&buff);
 *		return (-2);
 *	}
 *
 *	write(1, buff, strlen(buff));
 *	write(1, "\n", 1);
 *
 *	free_ptr(&buff);
 *	return (0);
 *}
 */
