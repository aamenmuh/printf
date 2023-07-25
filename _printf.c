#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "helper.h"
/**
 * _printf - prints
 * @format: format specifier
 *
 * Return: returns number of printed characters
 */
int _printf(char * format, ...)
{
	va_list ap;
	char c, *s;
	int d, count, len;
	len = 0;
	count = 0;
	
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format != '%')
		{
		write(1, format, 1);
		count++;
		}
		else{
			format++;
			switch(*format){
				case 'c':
				{
					c = (char)va_arg(ap, int);
					write(1, &c, 1);
					count++;
					break;
				}
				case 's':
				{
					s = va_arg(ap, char *);
					while (s[len] != '\0')
						len++;
					write(1, s, len);
					count += len;
					break;
				}
				case 'd':
				{
					d = va_arg(ap, int);
					s = toString(d);
					while (s[len] != '\0')
						len++;
					write(1, s, len);
					count += len;
					break;
				}
				case 'i':
				{
					d = va_arg(ap, int);
					s = toString(d);
					while (s[len] != '\0')
						len++;
					write(1, s, len);
					count += len;
					break;
				}
				case 'b':
				{
					b = va_arg(ap, int);
					s = toBinary(b);
					while (s[len] != '\0')
						len++;
					write(1, s, len);
					count += len;
					break;
				}
				case '%':
				{
					c = '%';
					write (1, &c, 1);
					count++;
					break;
				}
				default:
					break;
			}
			len = 0;
		}
		format++;
	}
	return (count);
}
