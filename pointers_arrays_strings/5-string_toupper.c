# include "main.h"

/**
 * string_toupper - Converts all lowercase letters of a string to uppercase.
 * @str: The string to convert.
 *
 * Return: A pointer to the converted string (the same string `str`).
 */

char *string_toupper(char *str)
{
	int index;

	for (index = 0; str[index] >= 97 && str[index] <= 122; index++)
		str[index] -= 32;
	return (str);
}
