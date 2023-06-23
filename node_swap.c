#include "sort.h"

void swap(listint_t *node1, listint_t *node2)
{
        listint_t *prev;
        listint_t *next;

        prev = node2->prev;
        next = node2->next;

        node2->next = node1->next;
        node2->prev = node1->prev;

        node1->prev = prev;
        node1->next = next;
}
