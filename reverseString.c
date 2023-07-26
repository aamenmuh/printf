#include <stdlib.h>
/**
 * reverseString - reverses a string
 * @str: the string
 *
 * Return: returns reversed string
 */
char *reverseString(char *str)
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
		s[i] = str[length - i - 1];
	}
	s[i] = '\0';
	return s;
}
