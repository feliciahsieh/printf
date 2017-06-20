#include <stdarg.h>
#include <stddef.h>
#include "holberton.h"
#define NUM_CS 7
/**
 * printf_process - process the printf variants
 * @v: variatic list
 * @format: printf format line
 * @i: current index of format
 * Return: total characters printed
 */
int printf_process(va_list v, char nextchar)
{
	_printf_t p[NUM_CS] = {
		{'c', printf_char},
		{'s', printf_string},
		{'%', printf_percent},
		{'d', printf_integer},
		{'i', printf_integer},
		{'o', printf_octal},
		{'\0', NULL}
	};
	int total = 0, j = 0;

	while (p[j].prType)
	{
		if (nextchar == p[j].prType)
		{
			total += p[j].f(v);
			return (total);
		}
		j++;
	}
	if (j == NUM_CS)
	{
		total += _putchar('%');
		total += _putchar(nextchar);
	}

	return (total);
}
