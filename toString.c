#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include "helper.h"

/**
 * toString - converts int to string
 * @num: the number
 *
 * Return: returns string rep of num
 */
char *toString(int num)
{
	int length = 0, i;
	char *str;
	int isNegative;

	isNegative = 0;

	length = countDigits(num);
	if (num == 0)
	{
		return (strdup("0"));
	}
	if (num < 0)
	{
		length += 1;
		isNegative = 1;
		num = -1 * num;
	}
	str = (char *)malloc(length * sizeof(char));
	if (str == NULL)
		return (str);

	i = length - 1;
	str[i--] = '\0';
	while (num != 0)
	{
		str[i--] = '0' + (num % 10);
		num /= 10;
	}
	if (isNegative)
		str[i--] = '-';
	return (&str[i + 1]);
}
