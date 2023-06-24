#include <stdio.h>
#include "sort.h"
#include <stdlib.h>

void insertion_sort_list(listint_t **list)
{
	if (!(*list) || !(*list)->next)
		return;

	listint_t *sorted = NULL;
	listint_t *current = *list;
	listint_t *nextNode = NULL;
	listint_t *temp = NULL;

	while (current)
	{
		nextNode = current->next;
		if (!sorted || current->n < sorted->n)
		{
			current->next = sorted;
			if (sorted)
				sorted->prev = current;
			sorted = current
		}
		else
		{
			temp = sorted;
			while (temp->next && temp->next->n < current->n)
				temp = temp->next;
			current->next = temp->next;
			if (temp->next)
				temp->next->prev = current;
			temp->next = 	
		}
		current = nextNode
	}
	*list = sorted

}
