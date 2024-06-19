#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: prints number from 0 to 9
 * Return: 0 successful
 */

int main(void)
{
	char num;

	for (num = 0; num <= 9; num++)
	{
		putchar(num + '0');
	}

	putchar('\n');

	return (0);
}
