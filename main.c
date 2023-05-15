#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	char *command, path[PATH_MAX];

	command = (char *)malloc(1024 * sizeof(char));
	getcwd(path, sizeof(path));

	if (command == NULL)
	{
		/* print error to stderror */
		return 1;
	}

	while (1)
	{
		printf("$ %s ", path);
		if (fgets(command, 1024, stdin) == NULL)
		{
			/* print error to stderror */
			break;
		}
		// parse the command here.
		// execute the command here.
		if (strcmp(command, "exit\n") == 0)
			break;
	}
	free(command);
	return (0);
}