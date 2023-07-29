#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include "helper.h"
/**
 * _printf - prints
 * @format: format specifier
 *
 * Return: returns number of printed characters
 */
int _printf(char *format, ...)
{
	va_list ap;
	char c, *s;
	int d, count, len;
	unsigned int b;
	void *ptr;

	len = 0;
	count = 0;
	if (format == NULL)
		return (0);
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format != '%')
		{
		write(1, format, 1);
		count++;
		}
		else
		{
			format++;
			if (*format == '\0')
			{
				break;
			}
			switch (*format)
			{
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
				if (s == NULL)
					s = "(null)";
				count += printConverted(s, len);
				break;
			}
			case 'S':
			{
				s = va_arg(ap, char *);
				count += printConverted(convertStringtoASCii(s), len);
				break;
			}
			case 'r':
			{
				s = va_arg(ap, char *);
				count += printConverted(reverseString(s), len);
				break;
			}
			case 'R':
			{
				s = va_arg(ap, char *);
				count += printConverted(CaeserCipher(s, 13), len);
				break;
			}
			case 'd':
			case 'i':
			{
				d = va_arg(ap, int);
				count += printConverted(toString(d), len);
				break;
			}
			case 'u':
			{
				b = va_arg(ap, int);
				count += printConverted(unsignedToStr(b), len);
				break;
			}
			case 'b':
			{
				b = va_arg(ap, int);
				count += printConverted(toBinary(b), len);
				break;
			}
			case 'x':
			case 'X':
			{
				d = va_arg(ap, int);
				if (*format == 'x')
					s = toAnyBase(d, 16, 'a');
				else
					s = toAnyBase(d, 16, 'A');
				count += printConverted(s, len);
				break;
			}
			case 'o':
			{
				d = va_arg(ap, int);
				count += printConverted(toAnyBase(d, 8, 'a'), len);
				break;
			}
			case 'p':
			{
				ptr =  va_arg(ap, void *);
				count += printConverted(toHex((uintptr_t) ptr, 'a'), len);
				break;

			}
			case '%':
			{
				c = '%';
				write(1, &c, 1);
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
	va_end(ap);
	return (count);
}
