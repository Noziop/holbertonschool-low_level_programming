#include "main.h"

/**
 * _strncat - function that concatenates two strings
 *@dest:
 *@src:
 *@n:
 *
 * Return:
 */

char *_strncat(char *dest, char *src, int n)
{
	int i = 0;
	int j = 0;
	char *bla = &*dest;

	while (dest[i])
	{
		i++;

	}
	while (src[j] != '\0' && j < n)
	{
			bla[i] = src[j];
			i++;
			j++;
	}
	bla[i + j] = '\0';
	return (bla);
}
