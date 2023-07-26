#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include "helper.h"

/**
 * toBinary - converts unsigned int to binary
 * @num: the number
 *
 * Return: returns string rep of num
 */
char *toBinary(unsigned int num)
{
	int length, i;
	char *str;

	if (num == 0)
		return strdup("0");

	length = countDigits(num);
	str = (char *)malloc((length + 1) * sizeof(char));
	if (str == NULL)
		return (str);

	i = length - 1;
	str[i--] = '\0';
	while (num != 0)
	{
		str[i--] = '0' + (num & 1);
		num >>= 1;
	}
	return (&str[i + 1]);
}
