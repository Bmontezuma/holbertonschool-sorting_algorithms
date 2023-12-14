#include <stdio.h>

// A utility function to swap two elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// A function that partitions the array using the last element as the pivot
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot element
    int i = low - 1; // index of smaller element

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]); // swap the elements
            printf("Swapped %d and %d\n", arr[i], arr[j]); // print the array after swapping
        }
    }
    swap(&arr[i + 1], &arr[high]); // place the pivot in its correct position
    printf("Swapped %d and %d\n", arr[i + 1], arr[high]); // print the array after swapping
    return i + 1; // return the index of the pivot
}

// A function that implements Quick sort
void quick_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        // Partition the array and get the pivot index
        int pi = partition(arr, low, high);

        // Recursively sort the subarrays on the left and right of the pivot
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

// A function to print an array
void print_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver code
int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Original array: \n");
    print_array(arr, size);
    quick_sort(arr, 0, size - 1);
    printf("Sorted array: \n");
    print_array(arr, size);
    return 0;
}

