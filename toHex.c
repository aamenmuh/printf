#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include "helper.h"
/**
 * toHex - converts to hex
 * @num: number
 * @base: eitehr 'a' or 'A'
 *
 * Return: Hex rep of num
 */
char *toHex(int num, char base)
{
	int length, i;
	char *str;
	int currentValue;

	if (num == 0)
        return strdup("0");

    if (base != 'a' && base != 'A')
        return NULL;

	length = 8;
	str = (char *)malloc((length + 1) * sizeof(char));
	if (str == NULL)
		return (str);
	i = length - 1;
	str[i--] = '\0';
	while (num != 0)
	{
		currentValue = num % 16;
		if (currentValue < 10)
			str[i--] = '0' + (currentValue);
		else
			str[i--] = base + (currentValue - 10);
		num /= 16;
	}
	return (&str[i + 1]);
}
