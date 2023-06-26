#include <stdio.h>
#include "sort.h"
#include <stdlib.h>

/**
 * insertion_sort_list - sorts a doubly linked lis using insertion sort
 *
 * @list: The list to be sorted
 * Description: Insertion sort algorithm divides the array into sub arrays
 * sorted and unsorted Takes an element from the unsorted and find the proper
 * postion for it in the sorted array
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *nextNode;

	if (!list || !(*list) || !(*list)->next)
		return;

	current = *list;
	nextNode = NULL;

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
