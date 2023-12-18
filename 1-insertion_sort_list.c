#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
void sorted_insert(listint_t **head, listint_t *node)
{
	listint_t *current;

	if (*head == NULL || (*head)->n >= node->n)
	{
		node->next = *head;
		if (*head != NULL)
			(*head)->prev = node;
			*head = node;
	}
	else
	{
	current = *head;
	while (current->next != NULL && current->next->n < node->n)
		current = current->next;

	node->next = current->next;
	if (current->next != NULL)
		current->next->prev = node;
	current->next = node;
	node->prev = current;
	}
}

void insertion_sort_list(listint_t **list)
{
	listint_t *sorted, *current, *next;

	sorted = NULL;
	current = *list;

	while (current != NULL)
	{
	next = current->next;

	current->prev = NULL;
	current->next = NULL;

	sorted_insert(&sorted, current);

	print_list(sorted);

	current = next;
	}

	*list = sorted;
}
