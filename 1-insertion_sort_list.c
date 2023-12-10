#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order
 * using the Insertion sort algorithm.
 * @list: A pointer to the doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    listint_t *current = (*list)->next;
    while (current != NULL)
    {
        listint_t *back = current->prev;
        while (back != NULL && back->n > current->n)
        {
            /* Swap nodes */
            if (back->prev != NULL)
                back->prev->next = current;
            if (current->next != NULL)
                current->next->prev = back;

            back->next = current->next;
            current->prev = back->prev;

            current->next = back;
            back->prev = current;

            /* Update list if back was the head */
            if (back == *list)
                *list = current;

            /* Print list after each swap */
            print_list(*list);

            /* Move back pointer backward */
            back = current->prev;
        }

        /* Move current pointer forward */
        current = current->next;
    }
}

int main(void)
{
    /* Test your function here if needed */
    return 0;
}
