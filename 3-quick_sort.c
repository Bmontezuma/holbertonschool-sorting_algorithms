#include "sort.h"

/* Function declarations */
void exchange_elements(int *a, int *b);
int lomuto_partition(int *array, size_t size, int low, int high);
void quick_sort_recursive(int *array, size_t size, int low, int high);
void quick_sort(int *array, size_t size);

/**
 * exchange_elements - Swap two elements in an array.
 * @a: Pointer to the first element.
 * @b: Pointer to the second element.
 */
void exchange_elements(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * lomuto_partition - Perform Lomuto partition and reorder array.
 * @array: Array to be partitioned.
 * @size: Size of the array.
 * @low: Starting index of the partition.
 * @high: Ending index of the partition.
 *
 * Return: Final partition index.
 */
int lomuto_partition(int *array, size_t size, int low, int high)
{
    int *pivot = array + high;
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (array[j] < *pivot)
        {
            i++;
            if (i != j)
            {
                exchange_elements(array + i, array + j);
                print_array(array, size);
            }
        }
    }

    if (array[i + 1] > *pivot)
    {
        exchange_elements(array + i + 1, pivot);
        print_array(array, size);
    }

    return i + 1;
}

/**
 * quick_sort_recursive - Recursively apply quicksort algorithm.
 * @array: Array to be sorted.
 * @size: Size of the array.
 * @low: Starting index of the array.
 * @high: Ending index of the array.
 */
void quick_sort_recursive(int *array, size_t size, int low, int high)
{
    if (low < high)
    {
        int partition_index = lomuto_partition(array, size, low, high);
        quick_sort_recursive(array, size, low, partition_index - 1);
        quick_sort_recursive(array, size, partition_index + 1, high);
    }
}

/**
 * quick_sort - Sort an array of integers using the quicksort algorithm.
 * @array: Array to be sorted.
 * @size: Size of the array.
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quick_sort_recursive(array, size, 0, size - 1);
}

