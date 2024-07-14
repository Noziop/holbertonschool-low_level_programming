#include "main.h"

/**
 * _calloc - Allocates memory for an array, using calloc.
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

	return (ptr);
	free(ptr);
}
