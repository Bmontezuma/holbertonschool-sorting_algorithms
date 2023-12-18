#include "sort.h"

/**
 * _swap - swap two elements in an array
 * @array: array of integers
 * @i: index of the first element
 * @j: index of the second element
 * @size: size of the array
 */
void _swap(int *array, int i, int j, size_t size)
{
    if (i != j && array[i] != array[j])
    {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
        print_array(array, size);
    }
}

/**
 * partition - partition the array using the last element as the pivot
 * @array: array of integers
 * @low: starting index of the partition
 * @high: ending index of the partition
 * @size: size of the array
 * Return: index of the pivot element
 */
int partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            _swap(array, i, j, size);
        }
    }
    _swap(array, i + 1, high, size);
    return i + 1;
}

/**
 * quicksort_recursive - recursively sort the partitioned array
 * @array: array of integers
 * @low: starting index of the partition
 * @high: ending index of the partition
 * @size: size of the array
 */
void quicksort_recursive(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int pivot = partition(array, low, high, size);
        quicksort_recursive(array, low, pivot - 1, size);
        quicksort_recursive(array, pivot + 1, high, size);
    }
}

/**
 * quick_sort - sort an array of integers in ascending order using quicksort
 * @array: array of integers
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;
    quicksort_recursive(array, 0, size - 1, size);
}

