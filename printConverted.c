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
	int length = len;

	while (str[length] != '\0')
		length++;

	write(1, &str[len], length - len);
	return (length - len);
}
