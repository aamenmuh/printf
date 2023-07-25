#include <unistd.h>
/**
 * printConverted - prints strings
 * @str: string
 * @len: initial index
 *
 * Return: returns length
 */
int printConverted(char *str, int len)
{
	while (str[len] != '\0')
		len++;
	write(1, str, len);
	return (len);
}
