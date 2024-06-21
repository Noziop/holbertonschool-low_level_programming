#include "main.h"

/**
* print_last_digit - eponym function
*@z: value being tested.
*
*Description: print absolute value
*Return: 0 if success
*/

int print_last_digit(int z)
{
	int x = z % 10;

	if (x < 0)
		x *= -1;

	_putchar(x + '0');
	return (x);
}
