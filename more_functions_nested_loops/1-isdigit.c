#include "main.h"

/**
 * _isdigit - determine wether a char is digit or not
 *@c: char to be tested
 *
 *Return:	1 if digit
 *			2 if not
 */

int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
