#include "main.h"
/**
 * main - Entry point
 *
 * Description: using _putchar to print "_putchar"
 * Return: 0 successful
 */

int main(void)
{
	char c[8] = "_putchar";
	int i;

	for (i = 0; i < 8; i++)
	{
		_putchar(c[i]);
	}
	_putchar('\n');

	return (0);
}
