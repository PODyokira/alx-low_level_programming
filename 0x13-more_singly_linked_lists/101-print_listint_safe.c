#include "lists.h"
#include <stdio.h>

size_t looped_listint_len(const listint_t *h);
size_t print_listint_safe(const listint_t *h);

/**
 * looped_listint_len - Counts the number of unique nodes
 * in a looped listint_t linked list.
 * @h: A pointer to the h of the listint_t to check.
 *
 * Return: If the list is not looped - 0.
 * Otherwise - the number of unique nodes in the list.
 */
size_t looped_listint_len(const listint_t *h)
{
	const listint_t *tortoise, *hare;
	size_t nodes = 1;

	if (h == NULL || h->next == NULL)
		return (0);

	tortoise = h->next;
	hare = (h->next)->next;

	while (hare)
	{
		if (tortoise == hare)
		{
			tortoise = h;
			while (tortoise != hare)
			{
				nodes++;
				tortoise = tortoise->next;
				hare = hare->next;
			}

			tortoise = tortoise->next;
			while (tortoise != hare)
			{
				nodes++;
				tortoise = tortoise->next;
			}

			return (nodes);
		}

		tortoise = tortoise->next;
		hare = (hare->next)->next;
	}

	return (0);
}

/**
 * print_listint_safe - Prints a listint_t list safely.
 * @h: A pointer to the h of the listint_t list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *h)
{
	size_t nodes, index = 0;

	nodes = looped_listint_len(h);

	if (nodes == 0)
	{
		for (; h != NULL; nodes++)
		{
			printf("[%p] %d\n", (void *)h, h->n);
			h = h->next;
		}
	}

	else
	{
		for (index = 0; index < nodes; index++)
		{
			printf("[%p] %d\n", (void *)h, h->n);
			h = h->next;
		}

		printf("-> [%p] %d\n", (void *)h, h->n);
	}

	return (nodes);
}
