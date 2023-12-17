#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using the Insertion Sort algorithm.
 * @list: A pointer to the head of the doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *sorted, *curr, *next, *aux, *temp;

	sorted = NULL;
	curr = *list;

	while (curr != NULL)
	{
		next = curr->next;
		curr->prev = curr->next = NULL;

		if (sorted == NULL || sorted->n > curr->n)
		{
			curr->next = sorted;
			if (sorted != NULL)
				sorted->prev = curr;
			sorted = curr;
		}
		else
		{
			aux = sorted;
			while (aux->next != NULL && aux->next->n <= curr->n)
				aux = aux->next;

			temp = aux->next;
			aux->next = curr;
			curr->prev = aux;
			curr->next = temp;

			if (temp != NULL)
				temp->prev = curr;
		}
		curr = next;
	}
	*list = sorted;
}

