#include "main.h"

/**
 * from_0_to_9 - loop for times table
 *
 * Description: create the for loop to increment
 * Return: Result to times_tabe
 *
*/
int from_0_to_9(void)
{
	int i, j, x;

	for (i = 0; i <= 9; i++)
	{
		_putchar('0');

		for (j = 1; j <= 9; j++)
		{
			x = i * j;

			_putchar(',');
			_putchar(' ');

			if (x <= 9)
				_putchar(' ');
			else
			{
				_putchar(x / 10 + '0');
			}
			_putchar(x % 10 + '0');
		}
		_putchar('\n');
	}
	return (0);
}

/**
 * times_table - entry point
 *
 * Description: prints every times table from 0 to 9
 * Return: all the tables to main
 */

void times_table(void)
{
	from_0_to_9();
}
