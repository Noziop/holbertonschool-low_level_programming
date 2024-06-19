#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: prints digit and combs : 0, 1, 2, etc...
 * Return: 0 successful
 */

int main(void)
{
	char digit;

	for (digit = 0; digit <= 9; digit++)
	{
		putchar(digit + '0');
		if (char == 9)
			continue;
		putchar(',');
		putchar(' ');
	}


	putchar('\n');

	return (0);
}
