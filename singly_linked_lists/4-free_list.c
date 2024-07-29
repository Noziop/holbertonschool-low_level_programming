#include "lists.h"

/**
 * free_list - libère la mémoire allouée pour la liste
 *
 * @head: pointeur vers la tête de la liste
 *
 * Return: none
 */

void free_list(list_t *head)
{
	list_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp->str);
		free(temp);
	}
}
