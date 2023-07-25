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
	unsigned int b;
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
					count += printConverted(s, len);
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
						s = toAnyBase(d,16 ,'a');
					else
						s = toAnyBase(d,16 ,'A');
					count += printConverted(s, len);
					break;
				}
			case 'o':
				{
					d = va_arg(ap, int);
					count += printConverted(toAnyBase(d, 8, 'a'), len);
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
