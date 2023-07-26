#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include "helper.h"
/**
 * CaeserCipher - applies Caeser cipher
 * @str: string
 * @shift: amount to shift
 *
 * Return: modified string
 */
char *CaeserCipher(char *str, int shift)
{
	int i, length = 0;
	char *s;

	i = 0;
	while (str[i] != '\0')
	{
		length++;
		i++;
	}
	s = malloc((length + 1) * sizeof(char));
	if (s == NULL)
		return (s);
	for (i = 0; i < length; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			s[i] = (str[i] - 'A' + shift) % 26 + 'A';
		else if (str[i] >= 'a' && str[i] <= 'z')
			s[i] = (str[i] - 'a' + shift) % 26 + 'a';
		else
			s[i] = str[i];
	}
	s[i] = '\0';
	return (s);
}
