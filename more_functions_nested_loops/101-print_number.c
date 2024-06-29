#include "main.h"

/**
 * print_number - Prints an integer using _putchar.
 * @n: The integer to be printed.
 */
void print_number(int n)
{
	int num = n;
	int divisor;

	if (n < 0)
	{
		_putchar('-');
		num = -n;
	}

	divisor = 1;

	while (num / divisor >= 10)
	{
		divisor *= 10;
	}

	while (divisor > 0)
	{
		int digit = num / divisor;

		_putchar(digit + '0');
		num %= divisor;
		divisor /= 10;
	}
}
