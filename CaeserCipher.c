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
		if (str[i] > 64 && str[i] < 91)
			s[i] = (str[i] + shift) % 26 + 65;
		else
			s[i] = (str[i] + shift) % 26 + 97;
	}
	return (s);
}
