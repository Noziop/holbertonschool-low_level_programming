#include <stdio.h>

/**
 * main - Finds and prints the largest prime
 *        factor of the number 612852475143.
 *
 * Return: Always 0.
 */

int main(void)
{
	long number = 612852475143;
	long factor = 2;
	long largest_prime = 0;

	while (number > 1)
	{
		if (number % factor == 0)
		{
			largest_prime = factor;
			while (number % factor == 0)
			{
				number /= factor;
			}
		}
		factor++;
	}

	printf("%ld\n", largest_prime);

	return (0);
}
