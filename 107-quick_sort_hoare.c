#include <stdio.h>
#include "sort.h"

/**
 * hoare_partition - Perform the Hoare partition scheme
 * @array: The array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array
 * Return: The index of the pivot
 */
size_t hoare_partition(int *array, size_t low, size_t high, size_t size)
{
    int pivot = array[high];
    int temp;
    size_t i = low - 1, j = high + 1;

    while (1)
    {
        do
        {
            i++;
        } while (array[i] < pivot);

        do
        {
            j--;
        } while (array[j] > pivot);

        if (i >= j)
            return j;

        /* Swap array[i] and array[j] */
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;

        printf("Swap: ");
        print_array(array, size);
    }
}

/**
 * quick_sort_hoare_recursive - Recursive function for Quick Sort (Hoare)
 * @array: The array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array
 */
void quick_sort_hoare_recursive(int *array, size_t low, size_t high, size_t size)
{
    if (low < high)
    {
        size_t pivot = hoare_partition(array, low, high, size);

        /* Recursively sort the two partitions */
        quick_sort_hoare_recursive(array, low, pivot, size);
        quick_sort_hoare_recursive(array, pivot + 1, high, size);
    }
}

/**
 * quick_sort_hoare - Quick Sort algorithm (Hoare partition scheme)
 * @array: The array to be sorted
 * @size: Size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quick_sort_hoare_recursive(array, 0, size - 1, size);
}
