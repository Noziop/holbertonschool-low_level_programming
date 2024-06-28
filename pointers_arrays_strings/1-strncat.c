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
	int k = 0;

	while (dest[i])
	{
		dest++;

	}
	while (k < n && src[j] != '\0')
	{
		dest[i + k] = src[j + k];
		i++;
		j++;
		k++;
	}
	dest[i + k] = '\0';
	return (dest);
}
