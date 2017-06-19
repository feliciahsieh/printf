#include <stdio.h>
#include <ctype.h>
#include <stdarg.h>
#include "holberton.h"

#define NIL_STR "(nil)"

/**
 * print_char - prints data of type character
 * @v: variatic list
 * Return: total characters printed
 */
int printf_char(va_list v)
{
	/*might need to typecast value to CHAR*/
        _putchar(va_arg(v, int));

	return (1);
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

	str = "";
	str++;

        str = va_arg(v, char *);
        if (str == NULL)
                return (0);

	while (str[i])
		_putchar(str[i++]);

	return (1);
}

/**
 * printf_percent - prints data of type %
 * @v: variatic list
 * Return: total characters printed
 */
int printf_percent(va_list v)
{
	char *str = NULL, *str2 = NULL;

	str = str2;
	str2 = str;

	str = va_arg(v, char *);
        _putchar('%');

	return (1);
}

/**
 * _printf - Entry point for all of printf
 * @format: format of incoming data to print
 * @...: variatic list
 * Return: total characters printed
 */
int _printf(const char * const format, ...)
{
	unsigned int totalchars = 0;

/*	_Printf_t p[4] = {
		{'c', printf_char},
		{'s', printf_string},
		{'%', printf_percent},
		{'\0', NULL}
	};
*/
	unsigned int i = 0;
/*	unsigned int j = 0;*/
	va_list ap;

	va_start(ap, format);
	while (format && format[i])
	{
		/*j = 0;*/

		switch (format[i])
		{
		case '%':
			if (format[i+1] == 'c')
			{
				printf_char(ap);
				totalchars++;
				i++;
			}
			else if (format[i+1] == 's')
			{
				printf_string(ap);
				totalchars++;
				i++;
			}
			else if (format[i+1] == '%')
			{
				_putchar('%');
				totalchars++;
				i++;
			}
			break;
			/*		case 92:
			_putchar('J');
			break;*/
		default:
			_putchar(format[i]);
			totalchars++;
			break;
		}

/*		while (p[j].printType)
		{
			if (format[i] == p[j].printType)
			{
				totalchars += p[j].f(ap);
				break;
			} else
			{
				_putchar(va_arg(ap, int));
				totalchars++;
			}

			j++;
		}

*/
		i++;
	}

	va_end(ap);

	/* Must return total chars printed */
	printf("TOTAL:%d\n",totalchars);
	return (totalchars);
}
