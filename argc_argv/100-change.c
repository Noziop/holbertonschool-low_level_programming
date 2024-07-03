#include <stdio.h>
#include <stdlib.h>

/**
 * main - calculates the minimum number of coins for change
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
	int coins[] = {25, 10, 5, 2, 1};
	int num_coins = sizeof(coins) / sizeof(coins[0]);
	int amount, numcoins = 0, i;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	amount = atoi(argv[1]);

	if (amount < 0)
	{
		printf("0\n");
		return (0);
	}

	for (i = 0; i < num_coins; i++)
	{
		numcoins += amount / coins[i];
		amount %= coins[i];
	}

	printf("%d\n", numcoins);
	return (0);
}
