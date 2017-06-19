#ifndef PRINT_F
#define PRINT_F

typedef struct _Printf
{
	char printType;
	int (*f)();
} _Printf_t;


int _putchar(char c);
int _printf(const char *format, ...);
#endif
