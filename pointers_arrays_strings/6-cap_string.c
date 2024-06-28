#include "main.h"

/**
 * cap_string - Capitalizes all words of a string.
 * @str: The string to capitalize.
 *
 * Return: A pointer to the modified string (the same string `str`).
 */

char *cap_string(char *str)
{
	int index = 0;
	int is_separator = 1;

	while (str[index])
	{
		if (is_separator && str[index] >= 'a' && str[index] <= 'z')
		{
			str[index] -= 'a' - 'A';
		}

		is_separator = !((str[index] >= 'a' && str[index] <= 'z') ||
						(str[index] >= 'A' && str[index] <= 'Z') ||
						(str[index] >= '0' && str[index] <= '9'));
		index++;
	}

	return (str);
}
