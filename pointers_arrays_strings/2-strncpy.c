#include "main.h"

/**
 * _strncpy - copies a string
 * @dest: destination
 * @src: soource
 * @n: number of char to cpy
 *
 * Return: dest
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;
	int j = 0;

	while (src[j] != '\0' && j < n && i < n)
	{
		dest[i] = src[j];
		i++;
		j++;
  	}
	dest[i + j] = '\0';
	return (dest);
}
