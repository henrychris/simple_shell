#include "shell.h"

/**
 * _getline - out getline function
 * @lineptr: lineptr
 * @n: size of line
 * @stream: stream
 * Return: ssize_t
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t i = 0, bufferSize = *n;
	char *buffer = *lineptr;
	ssize_t bytesRead;
	char ch;
	char *newBuffer;

	if (!lineptr || !n || !stream)
		return (-1);
	if (!buffer)
	{
		bufferSize = 128;
		buffer = (char *)malloc(bufferSize * sizeof(char));
		if (!buffer)
			return (-1);
	}
	while ((bytesRead = read(fileno(stream), &ch, 1)) > 0)
	{
		if (i >= bufferSize - 1)
		{
			bufferSize = bufferSize * 2;
			newBuffer = (char *)realloc(buffer, bufferSize * sizeof(char));
			if (!newBuffer)
			{
				free(buffer);
				return (-1);
			}
			buffer = newBuffer;
		}
		buffer[i++] = ch;
		if (ch == '\n')
			break;
	}
		buffer[i] = '\0';
		*lineptr = buffer;
		*n = bufferSize;
		if (bytesRead == -1)
			return (-1);
		return ((ssize_t)i);
}
