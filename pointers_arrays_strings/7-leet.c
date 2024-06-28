#include "main.h"
#include <ctype.h>

/**
 * leet - replace given chars by numbers
 * @str: string to be testeed
 * Return: pointer to the string.
 */

char *leet(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		char ch = _tolower(str[i]);

		switch (ch)
		{
			case 'a':
				str[i] = '4';
				break;
			case 'e':
				str[i] = '3';
				break;
			case 'o':
				str[i] = '0';
				break;
			case 'l':
				str[i] = '1';
				break;
			case 't':
				str[i] = '7';
				break;
			default:
				break;
		}
	}

	return (str);
}
