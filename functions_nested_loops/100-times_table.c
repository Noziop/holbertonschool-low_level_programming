#include "main.h"

void print_number(int n);
void spacer(void);
void print_spaces(int n);

/**
 * print_times_table - Prints the n times table, starting with 0.
 * @n: The number for which the times table should be printed.
 */
void print_times_table(int n)
{
	int i, j, product;

	if (n < 0 || n > 15)
		return;

	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= n; j++)
		{
			product = i * j;

			if (j != 0)
				spacer();
			print_spaces(product);
			print_number(product);
		}
		_putchar('\n');
	}
}

/**
 * print_number - Prints an integer using _putchar
 * @n: The integer to print
 */
void print_number(int n)
{
	if (n == 0)
	{
		_putchar('0');
		return;
	}

	if (n / 100)
	{
		_putchar((n / 100) + '0');
		_putchar(((n / 10) % 10) + '0');
		_putchar((n % 10) + '0');
	}
	else if (n / 10)
	{
		_putchar((n / 10) + '0');
		_putchar((n % 10) + '0');
	}
	else
	{
		_putchar(n + '0');
	}
}

/**
 * spacer - Prints a comma and a space
 */
void spacer(void)
{
	_putchar(',');
	_putchar(' ');
}

/**
 * print_spaces - Prints spaces based on the size of the number
 * @n: The integer to evaluate
 */
void print_spaces(int n)
{
	if (n < 10)
	{
		_putchar(' ');
		_putchar(' ');
	}
	else if (n < 100)
	{
		_putchar(' ');
	}
}
