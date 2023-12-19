#include "sort.h"

/**
 * _swap - Swaps two elements in an array
 * @array: Array to be sorted
 * @i: Index of the first element
 * @j: Index of the second element
 * @size: Size of the array
 */
void _swap(int *array, int i, int j, size_t size)
{
    if (i != j && array[i] != array[j])
    {
        int tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
        print_array(array, size);
    }
}

/**
 * partition - Partitions the array and returns the pivot index
 * @array: Array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array
 * Return: Pivot index
 */
int partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j <= high; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            _swap(array, i, j, size);
        }
    }

    _swap(array, i + 1, high, size);
    return (i + 1);
}

/**
 * quicksort - Recursive function to implement Quick sort
 * @array: Array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array
 */
void quicksort(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int pivot_index = partition(array, low, high, size);
        quicksort(array, low, pivot_index - 1, size);
        quicksort(array, pivot_index + 1, high, size);
    }
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort
 * @array: Array to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quicksort(array, 0, size - 1, size);
}

