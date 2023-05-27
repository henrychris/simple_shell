#include "shell.h"

/**
 * _memcpy - copies memory from the source to destination
 * @dest: destination
 * @src: source
 * @n: size of memory to be copied
 * Return: memory of destination
 */
void *_memcpy(void *dest, void *src, size_t n)
{
	char *cdest = (char *)(dest);
	const char *csrc = (const char *)(src);
	size_t i = 0;

	while (i < n)
	{
		cdest[i] = csrc[i];
		i++;
	}
	return (dest);
}

/**
 * _perror - prints an error message
 * @count: the number of commands executed so far
 * @command: the command that failed
 * @program_name: the name of the program
 * Return: void
 */
void _perror(int count, char *command, char *program_name)
{
	_write(program_name);
	_write(": ");
	write_number(count, 1);
	_write(": ");
	_write(command);
	_write(": not found\n");
}

/**
 * _write - prints a character
 * @s: string input
 */
void _write(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		_putchar(s[i]);
		i++;
	}
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 */
int _putchar(char c)
{
	return (write(2, &c, 1));
}

/**
 * write_number - writes a number to stdout
 * @number: the number to write
 * @fd: where to write to
 * Return: void
 */
void write_number(int number, int fd)
{
	char buffer[32];
	int length = 0, i;

	do {
		buffer[length++] = '0' + (number % 10);
		number /= 10;
	} while (number > 0);

	for (i = length - 1; i >= 0; i--)
	{
		write(fd, &buffer[i], 1);
	}
}
