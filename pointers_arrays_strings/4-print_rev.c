#include "main.h"

/**
 * print_rev - print a string in reverse mode
 *@s: string to be printed
 */

void print_rev(char *s)
{
	int i;

	while (s[i] != '\0')
	{
		i++;
	}
	while (i >= 0)
	{
		_putchar(s[i]);
		i--;
	}
	_putchar('\n');
}
