#include <stdio.h>
#include "sort.h"

void insertion_sort_list(listint_t **list)
{
	listint_t *x, *y, *z;

	if (!list || !*list || !(*list)->next)
		return;

	for (x = (*list)->next; x != NULL; x = y)
	{
		y = x->next;

		while (x->prev && x->n < x->prev->n)
		{
			z = x->prev;

			z->next = x->next;
			if (x->next)
				x->next->prev = z;
			x->next = z;
			x->prev = z->prev;
			x->next->prev = x;
			if (x->prev)
				x->prev->next = x;
			else
				*list = x;

			print_list(*list);
		}
	}
}
