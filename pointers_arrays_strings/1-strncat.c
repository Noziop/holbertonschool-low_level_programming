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

	while (dest[i])
	{
		dest++;

	}
	while (src[j] != '\0' && j < n)
	{
		dest[i + j] = src[j];
		i++;
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}
