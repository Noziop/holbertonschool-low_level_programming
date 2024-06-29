#include "main.h"

/**
 * print_number - Prints an integer using _putchar.
 * @n: The integer to be printed.
 */
void print_number(int n)
{
	int last_digit;

	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}

	if (n < 10)
	{
		_putchar(n + '0');
		return;
	}

	last_digit = n % 10;

	print_number(n / 10);
	_putchar(last_digit + '0');
}
