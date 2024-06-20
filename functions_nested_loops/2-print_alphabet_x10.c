#include "main.h"
/**
 * print_alphabet_x10 - writes the alphabet 10 times to stdout
 *
 *
 */
void print_alphabet_x10(void)
{

	int i;

	while (i < 10)
	{
		char az;

		az = 'a';

		while (az < 'z')
		{
			_putchar(az);
			az++;
		}
		_putchar('\n');
		i++;
	}
}
