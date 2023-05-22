#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *_strlite(char *str, const char *delim)
{
	int j = 0, i = 0, stop = 0;

	while (str[j])
	{
		if (str[j] == '\0')
			break;
		for (i = 0; i < strlen(delim); i++)
		{
			if (str[j] == delim[i])
			{
				str[j] = '\0';
				stop = 1;
				break;
			}
		}
		if (stop == 1)
			break;
		j++;
	}
	return (str);
}
char *_strtok(char *str, const char *delim)
{
	int i = 0;
	static char *p = NULL;

	if (str == NULL)
	{
		if (p == NULL)
			return (NULL);
		while (p[i])
		{
			if (p[i] == '\0')
			{
				if ((p + i + 1) == NULL)
					str = NULL;
				else
					str = (p + i + 1);
				break;
			}
			i++;
		}
	} else
	{
		if (p != NULL)
			free(p);
		p = malloc(1024 * sizeof(char));
		if (p == NULL)
		{
			perror("Fail");
			return (NULL);
		}
	}
	p = _strlite(str, delim);
	return (p);
}
int main(void)
{
	char s[] = "H,w";
	char *ptr;

	ptr = _strtok(s, ",");
	while (ptr)
	{
		printf("%s\n", ptr);
		ptr = _strtok(NULL, " ");
	}
	return (0);
}
