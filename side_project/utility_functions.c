#include "main.h"

/**
 * safe_malloc - Allocate memory safely
 * @size: Size of memory to allocate
 *
 * Return: Pointer to allocated memory, or NULL on failure
 */
void *safe_malloc(size_t size)
{
	void *ptr = malloc(size);

	if (!ptr)
	{
		fprintf(stderr, "Error: Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	return (ptr);
}

/**
 * safe_strdup - Safely duplicate a string
 * @str: String to duplicate
 *
 * Return: Pointer to the new string, or NULL on failure
 */
char *safe_strdup(const char *str)
{
	char *new_str = strdup(str);

	if (!new_str)
	{
		fprintf(stderr, "Error: String duplication failed\n");
		exit(EXIT_FAILURE);
	}
	return (new_str);
}
