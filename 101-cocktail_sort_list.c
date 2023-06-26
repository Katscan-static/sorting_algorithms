#include "sort.h"

/**
 * swap - Helper function to swap two nodes of a doubly linked list
 * @list: pointer to a doubly linked list
 * @node1: First node to swap
 * @node2: Second node to swap
 */
void swap(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev)
		node1->prev->next = node2;
	else
		*list = node2;

	if (node2->next)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node2->next = node1;
	node1->prev = node2;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list
 * @list: pointer to a doubly linked list
 * Description: Sorts a doubly linked list using the cocktail shaker
 * sort algorithm in ascending order
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *start = NULL, *current;
	listint_t *end = NULL;

	if (!list || !(*list) || !(*list)->next)
		return;

	do {
		swapped = 0;
		if (start)
			current = start;
		else
			current = *list;
		while (current->next != end)
		{
			if (current->n > current->next->n)
			{
				swap(list, current, current->next);
				swapped = 1;
				print_list(*list);
			}
			else
				current = current->next;
		}
		end = current;/*will help to reduce the num of comparisons*/
		if (!swapped)
			break;
		while (current->prev != start)
		{
			if (current->n < current->prev->n)
			{
				swap(list, current->prev, current);
				swapped = 1;
				print_list(*list);
			}
			else
				current = current->prev;
		}
		start = current;
	} while (swapped);
}
