#include "main.h"

/**
 * _printf - a replica of printf. Prints out a formatted string to the stdout
 * @format: the string to be formatted
 *
 * Return: the length of the formatted string
 */

int _printf(char *format, ...)
{
	int len, i = 0;
	int *integer;
	unsigned int ptr;
	char *s;

	va_list list;

	va_start(list, format);

	len = strlen(format);

	char *str = malloc(sizeof(format) * len);

	while (i < len)
	{
		str[i] = format[i];
		i++;
	}

	for (i = 0; i < len; i++)
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 'c')
			{
				ptr = va_arg(list, int);
				_putchar(ptr);
			}
			else if (str[i] == 'd')
			{
				ptr = va_arg(list, int);
				print_number(ptr);
			}
			else if (str[i] == 'i')
			{
				ptr = va_arg(list, int);
				print_number(ptr);
			}
			else if (str[i] == 's')
			{
				s = va_arg(list, char *);
				print_string(s);
			}
			else if (str[i] == '%')
			{
				_putchar('%');
			}
		}
		else
			_putchar(str[i]);
	}
	va_end(list);

	return (i);
}
