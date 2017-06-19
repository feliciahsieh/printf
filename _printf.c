#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdarg.h>
#include "holberton.h"

#define NIL_STR "(nil)"

/**
 * _printf - Entry point for all of printf
 * @format: format of incoming data to print
 * @...: variatic list
 * Return: total characters printed
 */
int _printf(const char * const format, ...)
{
	unsigned int totalchars = 0;

/*
	_Printf_t p[4] = {
		{'c', printf_char},
		{'s', printf_string},
		{'%', printf_percent},
		{'\0', NULL}
	};
*/
	unsigned int i = 0;
/*	int num = 0, d, t = 1, divisor;*/
	va_list ap;

	va_start(ap, format);
	while (format && format[i])
	{
		switch (format[i])
		{
		case '%':
			if (format[i + 1] == 'c')
			{
				printf_char(ap);
				totalchars++;
				i++;
			}
			else if (format[i + 1] == 's')
			{
				printf_string(ap);
				totalchars++;
				i++;
			}
			else if (format[i + 1] == '%')
			{
				_putchar('%');
				totalchars++;
				i++;
			}
			else if ((format[i + 1] == 'd') || (format[i + 1] == 'i'))
			{
/*
				num = va_arg(ap, int);
				can't get pow(10,9) working
				for (t = 0; t < 9; t++)
					divisor = divisor * 10;
				if (num < 0)
				{
					_putchar('-');
					totalchars++;
				}
				for (t = 0; t <= 9; t++)
				{
					_putchar('F');
					floating pt error
					d = (num / divisor) % 10;
					_putchar('H');
					if (num < 0)
						d = -d;
					_putchar('I');
					_putchar(d);
					divisor = divisor / 10;
				}
				need to add totalchars
*/
			}
			break;
		default:
			_putchar(format[i]);
			totalchars++;
			break;
		}

		i++;
	}

	va_end(ap);

	return (totalchars);
}
