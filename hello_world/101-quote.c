#include <unistd.h>

/**
 * main - prints and that piece of art is useful" - Dora Korpar, 2015-10-19
 *		folowed by a new line to stderr
 *
 * Return: Always 1
 */

int main(void)
{
	write(2, "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n", 60);

	return (1);
}
