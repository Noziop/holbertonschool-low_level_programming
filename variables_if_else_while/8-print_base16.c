#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: prints reverse alphabet
 * Return: 0 successful
 */

int main(void)
{
	char az09;

	for (az09 = 0; az09 <= 9; az09++)
	{
		putchar(az09 + '0');
	}
	for (az09 = 'a'; az09 <= 'f'; az09++)
	{
		putchar(az09);
	}

	putchar('\n');

	return (0);
}
