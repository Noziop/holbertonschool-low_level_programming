#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: prints the alphabet using putchar without 'q' and 'e'
 * Return: 0 successful
 */

int main(void)
{
	char az;

	for (az = 'a'; az <= 'z'; az++)
	{
		if (az != 'q' && az != 'e')
			putchar(az);
	}

	putchar('\n');

	return (0);
}
