#include "main.h"

/**
 * _strdup - returns a pointer to a newly allocated space in memory
 * @str: string to be copied
 * Return: a pointer to the duplicated string
 *         NULL if str is NULL or if insufficient memory was available
 */
char *_strdup(char *str)
{
	char *dst;
	unsigned int i, len = 0;

	if (str == NULL)
		return (NULL);

	/* Calculate length of str */
	while (str[len])
		len++;

	/* Allocate memory for the new string */
	dst = malloc(sizeof(char) * (len + 1));

	if (dst == NULL)
		return (NULL);

	/* Copy the string */
	for (i = 0; i <= len; i++)
		dst[i] = str[i];

	return (dst);
}
