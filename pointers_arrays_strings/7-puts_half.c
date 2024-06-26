#include "main.h"
/**
 * puts_half - prints half of a string, followed by a new line.
 * @str: string to be half printed
 */

void puts_half(char *str)
{
	int len = _strlen(str);
	int half = len / 2;
	int i;

	for (i = half; i < len; i++)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
}