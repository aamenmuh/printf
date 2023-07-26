#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#define MAX_UINT (4294967295)
#include <limits.h>
#include "helper.h"
/**
 * unsignedToStr - converts unsigned to str
 * @num: the number
 *
 * Return: returns string rep
 */
char *unsignedToStr(unsigned int num){
	int length;
	int i;
	char *str;
	length = 0;

	if (num <= INT_MAX)
		return toString(num);

	num = MAX_UINT + num + 1;
	length = 11;
	str = (char*)malloc((length + 1) * sizeof(char));
	if (str == NULL)
		return (str);
	i = length - 1;
	str[i--] = '\0';
	while (num != 0)
	{
		str[i--] = '0' + (num % 10);
		num /= 10;
	}
	return (&str[i + 1]);
}
