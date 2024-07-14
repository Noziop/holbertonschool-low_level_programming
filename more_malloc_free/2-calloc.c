#include "main.h"

/**
 * _calloc - Allocates memory for an array, using malloc.
 * @nmemb: The number of elements.
 * @size: The size of each element.
 *
 * Return: A pointer to the allocated memory.
 *			If nmemb or size is 0, returns NULL.
 *			If malloc fails, returns NULL.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *ptr;
	unsigned int total_size;

	total_size = nmemb * size;

	ptr = malloc(total_size);
	if (ptr == NULL || nmemb == 0 || size == 0)
		return (NULL);

	_memset(ptr, 0, total_size);

	return (ptr);
	free(ptr);
}

/**
 * _memset - fills the memery with b n time
 * @s: pointer to the memory area
 * @b: character to fill in memory
 * @n: The number of bytes to fill
 *
 * Return: pointer to the memory area if success
 *			return 1 if error
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i = 0;

	if (n == 0 || s == NULL)
	{
		return (s);
	}

	while (i < n)
	{
		s[i] = b;
		i++;
	}

	return (s);
}
