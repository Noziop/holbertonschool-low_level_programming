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
	char AZ;

	for (az = 'a'; az <= 'z'; az++)
	{
		putchar(az);
	}

	for (AZ = 'A'; AZ <= 'Z'; AZ++)
	{
		putchar(AZ);
	}

	putchar('\n');

	return (0);
}
