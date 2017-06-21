#include <stdarg.h>
#include "holberton.h"


/**
 * printf_S - prints custom S conversion specifier
 * @v: variatic list
 * Return: number of characters printed
 */
int printf_S(va_list v)
{
	char *s;
	char hex[17] = "0123456789ABCDEF";
	int total = 0, i = 0;

	(void)hex;
	s = va_arg(v, char *);

	while (s[i])
	{
		if (((s[i] >= 0) && (s[i] < 32)) || (s[i] >= 127))
		{
			_putchar('\\');
			_putchar('x');
			_putchar(s[i]);
			total += 3;
		}
		else
		{
			_putchar(s[i]);
			total++;
		}
	}

	return (total);
}
