#include <stdio.h>
#include "sort.h"
#include <stdlib.h>

/**
 * insertion_sort_list - sorts a doubly linked lis using insertion sort
 *
 * @list: The list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = *list;
	listint_t *nextNode = NULL;

	if (!list || !(*list) || !(*list)->next)
		return;

	while (current)
	{
		nextNode = current->next;

		while (current->prev && current->n < current->prev->n)
		{
			if (current->next)
				current->next->prev = current->prev;
			current->prev->next = current->next;
			current->next = current->prev;
			current->prev = current->prev->prev;
			current->next->prev = current;

			if (current->prev)
				current->prev->next = current;
			else
				*list = current;
			print_list(*list);
		}
		current = nextNode;
	}
}
