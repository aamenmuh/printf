#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
int _printf(char * format, ...)
{
    va_list ap;
    char c, *s;
    int count, len;
    count = 0;
	len = 0;
    
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
        }
        format++;
    }
    return count;
}
