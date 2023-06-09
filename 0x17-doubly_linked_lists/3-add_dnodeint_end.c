#include "lists.h"

/**
 * add_dnodeint_end - adds a node by the end of
 * doubly linked list
 * @head: head
 * @n: data
 * Return:  pointer to the newly created node
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *curr;
	dlistint_t *new_node = malloc(sizeof(dlistint_t));

	if (!new_node)
		return (NULL);

	new_node->prev = NULL;
	new_node->n = n;
	new_node->next = NULL;

	if (!*head)
	{
		*head = new_node;
		return (new_node);
	}
	curr = *head;

	while (curr->next)
		curr = curr->next;

	curr->next = new_node;
	new_node->prev = curr;

	return (new_node);
}
