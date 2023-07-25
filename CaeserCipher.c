#include <stdlib.h>
/**
 * CaeserCipher - applies Caeser cipher
 * @str: string
 * @shift: amount to shift
 *
 * Return: modified string
 */
char *CaeserCipher(char *str, int shift)
{
	int i, length;
	char *s;

	i = 0;
	while (str[i] != '\0')
	{
		length++;
		i++;
	}
	s = malloc((length + 1) * sizeof(char));
	i = 0;
	for (i = 0; i < length; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			s[i] = (str[i] - 'A' + shift) % 26 + 'A';
		else if (str[i] >= 'a' && str[i] <= 'z')
			s[i] = (str[i] - 'a' + shift) % 26 + 'a';
	}
	return (s);
}
