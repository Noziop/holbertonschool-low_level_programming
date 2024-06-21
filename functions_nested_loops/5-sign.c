#include "main.h"
/**
*print_sign - checks if n > or < or = to 0
*@n: checked character
*
*Description: checks if lowercase
*Return: 1 if greater
*		 0 if equal 0
*		-1 if smaller
*/
int print_sign(int n)
{
	if (n > 0)
	{
		_putchar('+');
		return (1);
	}
	else if (n == 0)
	{
		_putchar('0');
		return (0);
	}
	else if (n < 0)
	{
		_putchar('-');
		return (-1);
	}
	return (0);
}
