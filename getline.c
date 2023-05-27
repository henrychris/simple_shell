#include "shell.h"

/**
 * getLine - fetch a line
 * @line: pointer to first char
 * @fp: the stream to read from
 * Return: int showing status
 */
int getLine(char **line, FILE *fp)
{
	int bufflen = 80;
	char *buff = malloc(bufflen * sizeof(char)), c;
	int i = 0;

	if (*line != NULL)
	{
		free(buff);
		return (-1);
	}
	while (1)
	{
		if (i == bufflen - 1)
		{
			char *tempbuff = malloc(2 * bufflen * sizeof(char));

			strncpy(tempbuff, buff, bufflen);
			free(buff);
			buff = tempbuff;
			tempbuff = NULL;
			bufflen = bufflen * 2;
		}
		c = fgetc(fp);
		if (c == '\n' || c == EOF)
		{
			buff[i] = '\0';
			break;
		}
		else if (c == '\b' && i > 0)
			i = i - 2;
		else
			buff[i] = c;
		i++;
	}

	/* copy buff into line*/
	*line = malloc((i + 1) * sizeof(char));
	strncpy(*line, buff, i + 1);
	free(buff);
	return (i);
}
