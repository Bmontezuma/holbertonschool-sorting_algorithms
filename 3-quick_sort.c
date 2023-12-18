#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
int partition(int *array, int low, int high);
void quick_sort_helper(int *array, int low, int high);

int partition(int *array, int low, int high)
{
	int pivot, i, j, temp;

	pivot = array[high];
	i = low - 1;

	for (j = low; j < high; j++)
	{
	if (array[j] <= pivot)
	{
		i++;
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}
	}

	i++;
	temp = array[i];
	array[i] = array[high];
	array[high] = temp;

	return (i);
}

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_helper(array, 0, size - 1);
}

void quick_sort_helper(int *array, int low, int high)
{
	int p;

	if (low < high)
	{
		p = partition(array, low, high);
		quick_sort_helper(array, low, p - 1);
		quick_sort_helper(array, p + 1, high);
	}
}
