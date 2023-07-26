#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include "helper.h"
/**
 * convertStringtoASCii - allow only printable chars
 * @str: string to be converted
 *
 * Return: converted string
 */
char *convertStringtoASCii(char *str)
{
	char *s, *buffer;
	int i = 0, j = 0;

	buffer = malloc(3 * sizeof(char));
	if (!buffer)
		return (NULL);
	buffer[0] = '0';
	buffer[1] = '0';
	buffer[2] = '\0';
	s = malloc(15 * sizeof(char));
	if (!s)
	{
		free(buffer);
		return (NULL);
	}
	while (str[i] != '\0')
	{
		if (!(str[i] > 31 && str[i] < 127))
		{
			s[j++] = '\\';
			s[j++] = 'x';
			buffer = toAnyBase(str[i], 16, 'A');
			if (buffer[1] == '\0')
			{
				buffer[2] = '\0';
				buffer[1] = buffer[0];
				buffer[0] = '0';
			}
			s[j++] = buffer[0];
			s[j++] = buffer[1];
		}
		else
		{
			s[j++] = str[i];
		}
		i++;
	}
	s[j] = '\0';
	free(buffer);
	return (s);
}
