#include "sort.h"
#include <stdio.h>
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
    if (node1->next == node2)
    {
        node1->next = node2->next;
        node2->prev = node1->prev;
        node2->next = node1;
        node1->prev = node2;
    }
    else
    {
        listint_t *temp1 = node1->next;
        listint_t *temp2 = node2->next;
        node1->next = temp2;
        node2->next = temp1;
        temp1 = node1->prev;
        temp2 = node2->prev;
        node1->prev = temp2;
        node2->prev = temp1;
    }
    if (*list == node1)
        *list = node2;
    else if (*list == node2)
        *list = node1;
    if (node1->next == NULL)
        *list = node1;
    else if (node2->next == NULL)
        *list = node2;
    if (node1->next != NULL)
        node1->next->prev = node1;
    if (node1->prev != NULL)
        node1->prev->next = node1;
    if (node2->next != NULL)
        node2->next->prev = node2;
    if (node2->prev != NULL)
        node2->prev->next = node2;
}

void print_list(const listint_t *list)
{
    while (list)
    {
        printf("%d\n", list->n);
        list = list->next;
    }
}

void insertion_sort_list(listint_t **list)
{
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    listint_t *sorted = *list;
    listint_t *current = (*list)->next;

    while (current != NULL)
    {
        if (current->n < sorted->n)
        {
            swap_nodes(list, sorted, current);
            print_list(*list);
            current = current->next;
        }
        else
        {
            sorted = sorted->next;
            if (sorted->next == NULL)
                current = current->next;
        }
    }
}
