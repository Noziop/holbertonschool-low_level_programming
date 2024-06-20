#include "main.h"
/**
 * print_alphabet_x10 - writes the alphabet 10 times to stdout
 *
 *
 */
void print_alphabet_x10(void)
{

	int i;
	char az;

	for (i = 0; i < 10; i++)
	{
		for (az = 'a'; az <= 'z'; az++)
		{
			_putchar(az);
		}
		_putchar('\n');
	}
}
