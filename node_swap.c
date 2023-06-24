#include "sort.h"
void swap(listint_t *node1, listint_t *node2)
{

	printf("node1 : %p\n", (void *) node1);
	printf("node2 val: %p\n",(void *) node2);
	printf("node2 prev val: %p\n",(void *) node2->prev);

	if (!node1->prev && !node1->next)
		return;

	node2->next = node1;
}
