#include "main.h"
/**
 * _printf - a replica of printf. Prints out a formatted string to the stdout
 * @format: the string to be formatted
 * Return: the length of the formatted string
 */
int _printf(const char *format, ...)
{
	int len, i = 0, j = 0;
	char *str;
	va_list list;

	va_start(list, format);
	len = strlen(format);
	str = malloc(sizeof(format) * len);

	while (i < len)
	{
		str[i] = format[i];
		i++;
	}
	for (i = 0; i < len; i++)
	{
		j++;
		if (str[i] == '%' && str[i] != '\0')
		{
			i++;
			if (str[i] == 'c')
			{
				_putchar(va_arg(list, int));
			}
			else if (str[i] == 'd' || str[i] == 'i')
			{
				print_number(va_arg(list, int));
				j++;
			}
			else if (str[i] == 's')
			{
				print_string(va_arg(list, char*));
				j++;
			}
			else if (str[i] == '%')
				_putchar('%');
		}
		else
			_putchar(str[i]);
	}
	str[len] = '\0';
	va_end(list);
	free(str);
	return (j);
}
