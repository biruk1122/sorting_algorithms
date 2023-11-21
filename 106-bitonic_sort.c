#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * bitonic_compare_swap - Swap elements if they are in the wrong order
 * @array: The array to be sorted
 * @i: Index of the first element
 * @j: Index of the second element
 * @dir: Sorting direction (1 for ascending, 0 for descending)
 * @size: Size of the array
 */
void bitonic_compare_swap(int *array, size_t i, size_t j, int dir, size_t size)
{
    if ((array[i] > array[j] && dir) || (array[i] < array[j] && !dir))
    {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
        printf("Swap: ");
        print_array(array, size);
    }
}

/**
 * bitonic_merge - Perform bitonic merge on the given array
 * @array: The array to be sorted
 * @low: Starting index of the subarray
 * @count: Number of elements in the subarray
 * @dir: Sorting direction (1 for ascending, 0 for descending)
 * @size: Size of the array
 */
void bitonic_merge(int *array, size_t low, size_t count, int dir, size_t size)
{
    if (count > 1)
    {
        size_t k = count / 2;
        size_t i;

        for (i = low; i < low + k; i++)
            bitonic_compare_swap(array, i, i + k, dir, size);

        bitonic_merge(array, low, k, dir, size);
        bitonic_merge(array, low + k, k, dir, size);
    }
}

/**
 * bitonic_sort_recursive - Recursive function for Bitonic Sort
 * @array: The array to be sorted
 * @low: Starting index of the subarray
 * @count: Number of elements in the subarray
 * @dir: Sorting direction (1 for ascending, 0 for descending)
 */
void bitonic_sort_recursive(int *array, size_t low, size_t count, int dir, size_t size)
{
    if (count > 1)
    {
        size_t k = count / 2;

        printf("Merging [%lu, %lu] (dir=%d)\n", low, low + count - 1, dir);
        bitonic_sort_recursive(array, low, k, 1, size);
        bitonic_sort_recursive(array, low + k, k, 0, size);

        printf("Merging [%lu, %lu] (dir=%d)\n", low, low + count - 1, dir);
        bitonic_merge(array, low, count, dir, size);
    }
}

/**
 * bitonic_sort - Bitonic Sort algorithm
 * @array: The array to be sorted
 * @size: Size of the array (must be a power of 2)
 */
void bitonic_sort(int *array, size_t size)
{
    bitonic_sort_recursive(array, 0, size, 1, size);
}
