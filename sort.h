#ifndef SORT_H
#define SORT_H

#include <stddef.h>



/* Structure for doubly linked list node */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

/* Function prototypes */
void selection_sort(int *array, size_t size);
void bubble_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void swap(int *a, int *b);
void quick_sort_recursive(int *array, int low, int high);
void quick_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void print_list(const listint_t *list);
void exchange_elements(int *a, int *b);
size_t lomuto_partition(int *array, int low, int high, size_t size);
void quicksort(int *array, int low, int high, size_t size);
void quick_sort(int *array, size_t size);
#endif /* SORT_H */

