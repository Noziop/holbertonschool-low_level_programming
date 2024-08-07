#include "main.h"

/**
 * create_array - creates an array of chars initializes it with a specific char
 * @size: the size of the memory to print
 * @c: char to print
 * Return: a pointer to the array
 *			NULL if it fails.
 */

char *create_array(unsigned int size, char c)
{
	char *array;
	unsigned int i;

	if (size == 0)
	{
		return (NULL);
	}

	array = malloc(sizeof(char) * size);
	if (array == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < size; i++)
	{
		array[i] = c;
	}

	return (array);

}

