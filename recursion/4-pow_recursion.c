#include "main.h"

/**
 * _pow_recursion - return the value of a number power a number
 * @x: base number
 * @y: powe
 * Return: value of x^y
 */

int _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);
	if (y == 0)
		return (1);
	if (y == 1)
		return (x);

	return (x * _pow_recursion(x, y - 1));
}
