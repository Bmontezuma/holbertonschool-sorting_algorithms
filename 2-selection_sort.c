#include "sort.h"
#include <stdio.h>

/**
 * print_array - Function to print the elements of an array.
 * @array: The array to print.
 * @size: The number of elements in the array.
 */
void print_array(const int *array, size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
	{
		printf("%d", array[i]);
		if (i < size - 1)
			printf(" ");
	}
	printf("\n");
}

/**
 * swap - Function to swap two elements in an array.
 * @a: Pointer to the first element.
 * @b: Pointer to the second element.
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * selection_sort - Function to implement selection sort algorithm on an array.
 * @array: The array to sort.
 * @size: The number of elements in the array.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}

		swap(&array[min], &array[i]);
		print_array(array, size);
	}
}

/**
 * main - Main function to demonstrate selection sort on an array.
 * Return: 0 on success.
 */
int main(void)
{
	int arr[] = {64, 25, 12, 22, 11};
	size_t size = sizeof(arr) / sizeof(arr[0]);

	/* Print the original array */
	print_array(arr, size);

	/* Perform selection sort */
	selection_sort(arr, size);

	/* Print the sorted array */
	print_array(arr, size);

	return (0);
}

