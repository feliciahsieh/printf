#include <stdio.h>
#include <stdarg.h>
#include "holberton.h"
/**
 * _printf - Entry point for all of printf
 * @format: format of incoming data to print
 * @...: variatic list
 * Return: total characters printed
 */
int _printf(const char * const format, ...)
{
	unsigned int totalchars = 0, i = 0;
	va_list ap;

	va_start(ap, format);
	while (format && format[i])
	{
		switch (format[i])
		{
		case '%':
			switch (format[i + 1])
			{
			case 'c':
				printf_char(ap);
				totalchars++;
				i++;
				break;
			case 's':
				printf_string(ap);
				totalchars++;
				i++;
				break;
			case '%':
				_putchar('%');
				totalchars++;
				i++;
				break;
			case 'd':
			case 'i':
				printf_integer(ap);
				break;
			default:
				_putchar(format[i]);
				totalchars++;
				break;
			}
		}
		i++;
	}
	va_end(ap);
	return (totalchars);
}
