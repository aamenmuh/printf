#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include "helper.h"
/**
 * toAnyBase - converts to any Base
 * @num: the number
 * @base: the base
 * @c: base character for > 9 (either 'A' or 'a')
 *
 * Return: returns converted number
 */
char *toAnyBase(int num, int base, char c)
{
	int length, i;
	char *str;
	int currentValue;

	if (num == 0)
		return (strdup("0"));
	length = 8;
	str = (char *)malloc((length + 1) * sizeof(char));
	if (str == NULL)
		return (str);
	i = length - 1;
	str[i--] = '\0';
	while (num != 0)
	{
		currentValue = num % base;
		if (currentValue < 10)
			str[i--] = '0' + (currentValue);
		else
			str[i--] = c + (currentValue - 10);
		num /= base;
	}
	return (&str[i + 1]);
}
