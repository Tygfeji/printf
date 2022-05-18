#include "main.h"

/**
 * _printf - sends the value of the output to stdio
 * @format: parameta
 * Return: integer 0
 */

int _printf(const char *format, ...)
{
	va_list args;
	int a, b, len = 0;
	char *str;

	va_start(args, format);
	for (a = 0; format[a] != '\0'; a++)
	{
		if (format[a] != '%')
		{
			_putchar(format[a]);
			len++;
		}
		else
		{
			if (format[a + 1] == 'c')
			{
				_putchar(va_arg(args, int));
				len++;
			}
			else if (format[a + 1] == 's')
			{
				str = va_arg(args, char *);
				for (b = 0; str[b] != '\0'; b++)
				{
					_putchar(str[b]);
					len++;
				}
			}
			else if (format[a + 1] == '%')
			{
				_putchar('%');
			}
			a++;
		}
	}
	va_end(args);
	return (len);
}

