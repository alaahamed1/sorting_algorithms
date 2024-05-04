#include <stdio.h>
#include "sort.h"

/**
 * swap - function that swaps two nodes in a doubly linked list
 * @a: pointer to the first node
 * @b: pointer to the second node
 */
void swap(listint_t *a, listint_t *b)
{
	if (a->prev)
		a->prev->next = b;
	if (b->next)
		b->next->prev = a;

	a->next = b->next;
	b->prev = a->prev;

	a->prev = b;
	b->next = a;
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: pointer to the head of the linked list
 */
void insertion_sort_list(listint_t **list)
{
	if (!list || !(*list) || !(*list)->next)
		return;

	listint_t *i, *j;

	for (i = (*list)->next; i != NULL; i = i->next)
	{
		for (j = i->prev; j != NULL && j->n > i->n; j = j->prev)
		{
			if (j->prev == NULL)
				*list = i;
			swap(j, i);
			if (j->prev == NULL)
				print_list(*list);
		}
	}
}
