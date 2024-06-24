#include "main.h"

/**
 * _isupper - determine if a character is wether upper or lowercase
 *@c: character to be tested
 *
 *Return:	1 if upper
 *			0 if lower
 */

int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}