#include "main.h"
#include <stdio.h>

/**
 *print_to_98 - entry point
 *@n: value transmitted for main
 *
 * Description: prints number from value transmitted by main to 98.
 * Return: 0 if successful
 */

void print_to_98(int n)
{
	if (n >= 98)
	{
		while (n > 98)
			printf("%d, ", n--);
		printf("%d\n", n);
	}
	else
	{
		while (n < 98)
			printf("%d, ", n++);
		printf("%d\n", n);
	}
}
