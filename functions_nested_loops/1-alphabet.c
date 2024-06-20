#include "main.h"
/**
 * print_alphabet - writes the alphabet to stdout
 *
 *
 */
void print_alphabet(void)
{
	char az[26] = "abcdefghijklmnopqrstuvwxyz";
	int i;

	for (i = 0; i <= 26; i++)
	{
		_putchar(az[i]);
	}
	_putchar('\n');
}
