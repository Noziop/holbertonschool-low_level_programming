#include "lists.h"

/**
 * list_len - retourne le nombre d'éléments dans une liste liée
 *
 * @h: pointeur vers la tête de la liste
 *
 * Return: le nombre d'éléments dans la liste
 */
size_t list_len(const list_t *h)
{
	size_t n = 0;

	while (h != NULL)
	{
		n++;
		h = h->next;
	}

	return (n);
}
