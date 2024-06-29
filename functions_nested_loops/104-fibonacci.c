#include <stdio.h>

/**
 * main - Prints the first 98 Fibonacci numbers,
 *			separated by a comma followed by a space.
 *
 * Return: Always 0.
 */
int main(void)
{
	int count;
	unsigned long fib1 = 1, fib2 = 2, nextTerm;

	printf("%lu, %lu, ", fib1, fib2);

	for (count = 3; count <= 98; count++)
	{
		nextTerm = fib1 + fib2;
		printf("%lu", nextTerm);

		if (count != 98)
			printf(", ");

		fib1 = fib2;
		fib2 = nextTerm;
	}

	printf("\n");
	return (0);
}
