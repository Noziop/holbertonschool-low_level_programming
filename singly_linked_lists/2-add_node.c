#include "lists.h"


/**
 * add_node - ajoute un nouveau nœud à la tête de la liste
 *
 * @head: pointeur vers la tête de la liste
 * @str: chaîne de caractères à ajouter à la liste
 *
 * Return: l'adresse du nouveau nœud, ou NULL si l'allocation a échoué
 */

list_t *add_node(list_t **head, const char *str)
{
	list_t *new_node;
	char *dup_str;

	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);

	dup_str = strdup(str);
	if (dup_str == NULL)
	{
		free(new_node);
		return (NULL);
	}

	new_node->str = dup_str;
	new_node->len = strlen(dup_str);
	new_node->next = *head;
	*head = new_node;

	return (new_node);
}
