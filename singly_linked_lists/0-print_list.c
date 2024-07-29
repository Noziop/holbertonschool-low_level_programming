#include "lists.h"

/**
 * print_list - Prints all elements of a linked list
 * @h: Pointer to the head of the list
 *
 * Return: The number of elements in the list
 */
size_t print_list(const list_t *h)
{
	size_t n = 0;

	while (h != NULL)
	{
		if (h->str == NULL)
			printf("[0] (nil)\n");
		else
			printf("[%u] %s\n", h->len, h->str);
		h = h->next;
		n++;
	}

	return (n);
}
