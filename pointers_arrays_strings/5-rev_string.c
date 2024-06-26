#include "main.h"

/**
 * rev_string - reverse a string
 *@s: string to be reversed
 */
void rev_string(char *s)
{
	print_rev(s);
}

/**
 * print_rev - print a string in reverse mode
 *@s: string to be printed
 */
void print_rev(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	i--;
	while (i >= 0)
	{
		_putchar(s[i]);
		i--;
	}
	_putchar('\n');
}