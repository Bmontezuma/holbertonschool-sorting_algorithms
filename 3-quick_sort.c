#include "sort.h"
#include <stdio.h>

/* Function prototype for lomuto_partition */
int lomuto_partition(int *array, int low, int high);

/**
 * quick_sort_recursive - Recursive function to perform quick sort
 * @array: Array to be sorted
 * @low: Starting index of the array or subarray
 * @high: Ending index of the array or subarray
 */
void quick_sort_recursive(int *array, int low, int high)
{
    if (low < high)
    {
        int pi = lomuto_partition(array, low, high);

        printf("\n");
        print_array(array, high - low + 1);

        quick_sort_recursive(array, low, pi - 1);
        quick_sort_recursive(array, pi + 1, high);
    }
}

/**
 * lomuto_partition - Lomuto partition scheme for Quick Sort
 * @array: Array to be sorted
 * @low: Starting index of the array or subarray
 * @high: Ending index of the array or subarray
 * Return: Partition index
 */
int lomuto_partition(int *array, int low, int high)
{
    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            if (i != j)
            {
                /* Swap array[i] and array[j] */
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                printf("Swapped %d and %d\n", array[i], array[j]);
            }
        }
    }

    /* Swap array[i + 1] and array[high] (pivot) */
    if (i + 1 != high)
    {
        int temp = array[i + 1];
        array[i + 1] = array[high];
        array[high] = temp;
        printf("Swapped %d and %d\n", array[i + 1], array[high]);
    }

    return i + 1;
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick Sort
 * @array: Array to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quick_sort_recursive(array, 0, size - 1);
}

