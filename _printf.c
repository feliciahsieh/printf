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
	unsigned int totalchars = 0, i = 0, prev_total = 0;
	va_list ap;

	va_start(ap, format);

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			totalchars += printf_process(ap, format, format[i + 1]);
		}
		else
		{
			totalchars += _putchar(format[i]);
		}
		i++;
	}

	va_end(ap);

	return (totalchars);
}
