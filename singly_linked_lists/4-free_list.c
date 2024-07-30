#include "lists.h"

/**
 * free_list - free allocated memory for the list
 *
 * @head: pointer to the head of list
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
