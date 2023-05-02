#include "lists.h"

/**
 * free_listint_safe - frees a linked list
 * @hhh: pointer to the first node in the linked list
 *
 * Return: number of elements in thhhe freed list
 */
size_t free_listint_safe(listint_t **hhh)
{
	size_t len = 0;
	int diff;
	listint_t *temp;

	if (!hhh || !*hhh)
		return (0);

	while (*hhh)
	{
		diff = *hhh - (*hhh)->next;
		if (diff > 0)
		{
			temp = (*hhh)->next;
			free(*hhh);
			*hhh = temp;
			len++;
		}
		else
		{
			free(*hhh);
			*hhh = NULL;
			len++;
			break;
		}
	}

	*hhh = NULL;

	return (len);
}






































