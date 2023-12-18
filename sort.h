#ifndef SORT_H
#define SORT_H

#include <stddef.h>
#include <stdio.h>

/* Structure for doubly linked list node */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;


/* Function prototypes */
void print_array(const int *array, size_t size);
void swap(int *a, int *b);
int lomuto_partition(int *array, int low, int high);
void quick_sort_recursive(int *array, int low, int high);
void quick_sort(int *array, size_t size);
int lomuto_partition(int *array, int low, int high);
void insertion_sort_list(listint_t **list);
void print_list(const listint_t *list);
void exchange_elements(int *a, int *b);
#endif /* SORT_H */

