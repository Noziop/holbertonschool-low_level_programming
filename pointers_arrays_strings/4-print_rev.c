#include "main.h"

/**
 * print_rev - print a string in reverse mode
 *@s: string to be printed
 */

void print_rev(char *s)
{
	if (*s == '\0')
	{
		return;
	}
	else
	{
		print_rev(s + 1);
		_putchar(*s);
	}
}
