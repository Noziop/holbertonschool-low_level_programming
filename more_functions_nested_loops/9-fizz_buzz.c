#include <stdio.h>

/**
 * main - prints from 1 to 100
 *			replacing multiple of 3 and 5 by fizzbuzz
 *			replacing multiple of 3 by fizz
 *			replacing multiple of 5 by buzz
 *
 * Return: 0 if successful
 */

int main (void)
{
	int i;

	for (i= 1; i <= 100; i++)
	{
		if ((i % 3 == 0) && (i % 5 == 0))
		{
			printf("FizzBuzz");
			putchar(' ');
		}
		else if (i % 3 == 0)
		{
			printf("Fizz");
			putchar(' ');
		}
		else if (i % 5 == 0)
		{
			printf("Buzz");
			putchar(' ');
		}
		else
		{
			printf("%d", i);
			putchar(' ');
		}
	}
	printf("\n");

	return (0);
}
