#include <stdio.h>
#include <limits.h>
#include <math.h>
#include "holberton.h"
int main()
{
	int divisor = 1, t, d, num;
	int num1 = INT_MAX;	/*2147483647 */
	int num2 = INT_MIN;	/*-2147483648*/
	int num3 = 0;
	int num4 = 234;
	char digits[12];
	int index = 0;
	int highestorderdigit = 0;
	int totalchars = 0;

	num = num4;

	divisor = pow(10,9);
/*	for (t = 0; t < 9; t++)
	divisor = divisor * 10;*/
	printf("num:%d\n", num);
	if (num < 0)
	{
		digits[index++] = '-';
		_putchar('-');
	}
	for (t = 0; t <= 9; t++)
	{
		d = (num / divisor) % 10;
		if (num < 0)
			d = -d;
		if ((d != 0) && !highestorderdigit)
			highestorderdigit = 1;
		if (highestorderdigit)
		{
			digits[index++] = d + '0';
			_putchar(d + '0');
			totalchars++;
		}
		divisor = divisor / 10;
	}
	if (totalchars == 0)
	{
		digits[index++] = '0';
		digits[index] = '\0';
		_putchar(d + '0');
		totalchars++;
	}

	_putchar('\n');
	digits[index] = '\0';

	printf("Output:%s\n", digits);
	return (0);
}
