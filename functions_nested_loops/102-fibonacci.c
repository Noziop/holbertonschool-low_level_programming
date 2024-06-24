#include <stdio.h>

/**
 * main - print a fibonacci
 *
 * Return: 0
 */

int main(void)
{
	int i;
	unsigned long a = 1, b = 2, next;

	for (i = 1; i <= 50; i++)
	{
		printf("%lu", a);

		if (i < 50)
			printf(", ");

		next = a + b;
		a = b;
		b = next;
	}

	printf("\n");

	return (0);
}
