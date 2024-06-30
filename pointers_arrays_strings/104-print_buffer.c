#include <stdio.h>
#include <ctype.h>

/**
 * print_hex - Prints the hex content of the buffer.
 * @b: The buffer to be printed.
 * @start: The starting byte index.
 * @size: The number of bytes to be printed.
 */
void print_hex(char *b, int start, int size)
{
	int index;

	for (index = 0; index < 10; index++)
	{
		if (start + index < size)
			printf("%02x", (unsigned char)b[start + index]);
		else
			printf("  ");

		if (index % 2 != 0)
			printf(" ");
	}
}

/**
 * print_chars - Prints the character content of the buffer.
 * @b: The buffer to be printed.
 * @start: The starting byte index.
 * @size: The number of bytes to be printed.
 */
void print_chars(char *b, int start, int size)
{
	int index;

	for (index = 0; index < 10; index++)
	{
		if (start + index < size)
		{
			char c = b[start + index];
			if (isprint(c))
				putchar(c);
			else
				putchar('.');
		}
		else
		{
			putchar(' ');
		}
	}
}

/**
 * print_buffer - Prints a buffer 10 bytes at a time, starting with
 *                the byte position, then showing the hex content,
 *                then displaying printable characters.
 * @b: The buffer to be printed.
 * @size: The number of bytes to be printed from the buffer.
 */
void print_buffer(char *b, int size)
{
	int byte;

	for (byte = 0; byte < size; byte += 10)
	{
		printf("%08x: ", byte);

		print_hex(b, byte, size);
		print_chars(b, byte, size);

		printf("\n");
	}

	if (size <= 0)
		printf("\n");
}
