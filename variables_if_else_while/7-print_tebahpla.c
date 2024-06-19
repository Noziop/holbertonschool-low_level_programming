#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: prints reverse alphabet
 * Return: 0 successful
 */

int main(void)
{
	char za;

	for (za = 'z'; za >= 'a'; za--)
	{
		putchar(za);
	}

	putchar('\n');

	return (0);
}
