#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: prints the alphabet using putchar
 * Return: 0 successful
 */

int main(void)
{
	char az;

	for (az = 'a'; az <= 'z'; az++)
	{
		putchar(az);
	}
	putchar('\n');

	return (0);
}
