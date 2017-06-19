#ifndef PRINTF_0
#define PRINTF_0
#include <stdarg.h>
#include <stddef.h>
#include "holberton.h"

/**
 * print_char - prints data of type character
 * @v: variatic list
 * Return: total characters printed
 */
int printf_char(va_list v)
{
	return (_putchar(va_arg(v, int)));
}

/**
 * printf_string - prints data of type string
 * @v: variatic list
 * Return: total characters printed
 */
int printf_string(va_list v)
{
	char *str = NULL;
	unsigned int i = 0;

	str = va_arg(v, char *);
	if (str == NULL)
	{
		_putchar('(');
		_putchar('n');
		_putchar('u');
		_putchar('l');
		_putchar('l');
		_putchar(')');
		return (6);
	}
	while (str[i])
		_putchar(str[i++]);

	return (i);
}

#endif
