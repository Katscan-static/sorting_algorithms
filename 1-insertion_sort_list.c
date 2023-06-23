#include <stdio.h>
#include "sort.h"
#include <stdlib.h>

void compare(listint_t *node1, listint_t *node2)
{
	if (node1->n > node2-n)
	{
		swap(node1, node2);

	}
	else
	{
		node1 = node2;
		node2 = node->next;
	}
	
}

void check_nodes(listint_t *node1, listint_t *node2)
{

	if (node1->prev)
	{
		node2 = node1
		node1 = node1->prev;
	}
	else
	{
		node1 = node2;
		node2 = node->next
	}

}
void insertion_sort_list(listint_t **list)
{

	if (!list or !*list)
		return;

	node1 = *list;
	node2 = current->next;
	

	
}
