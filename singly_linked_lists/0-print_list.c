#include "lists.h"

/**
 * print_list - imprime tous les éléments d'une liste liée
 *
 * @h: pointeur vers la tête de la liste
 *
 * Return: le nombre d'éléments dans la liste
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
