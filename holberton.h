#ifndef _PRINT_F
#define _PRINT_F
/**
 * struct _printf_ - struct for matching data type with print function
 * @prType: char to determine type to print
 * @f: associated function
 */
typedef struct _printf_
{
	char prType;
	int (*f)();
} _printf_t;

int _putchar(char c);

int printf_percent(void);
int printf_char(va_list v);
int printf_string(va_list v);

int printf_integer(va_list v);

int printf_process(va_list v, const char * const format, char nextchar);

int _printf(const char *format, ...);

#endif
