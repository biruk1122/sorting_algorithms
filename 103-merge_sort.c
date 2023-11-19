#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/* Function Prototypes */
void merge_sort(int *array, size_t size);
void merge(int *array, size_t size, int *left, size_t left_size, int *right, size_t right_size);

/**
 * merge_sort - Sorts an array of integers
 * @array: The array to be sorted
 * @size: The size of the array
 */
void merge_sort(int *array, size_t size)
{
	if (size > 1)
	{
		size_t mid = size / 2;
		int *left = array;
		size_t left_size = mid;
		int *right = array + mid;
		size_t right_size = size - mid;

		printf("Merging...\n");
		print_array(left, left_size);
		print_array(right, right_size);
		merge_sort(left, left_size);
		merge_sort(right, right_size);
		merge(array, size, left, left_size, right, right_size);
	}
}

/**
 * merge - Merges two sub-arrays into one sorted array
 * @array: The array containing both sub-arrays
 * @size: The size of the original array
 * @left: The left sub-array
 * @left_size: The size of the left sub-array
 * @right: The right sub-array
 * @right_size: The size of the right sub-array
 */
void merge(int *array, size_t size, int *left, size_t left_size, int *right, size_t right_size)
{
	size_t i = 0, j = 0, k = 0;
	int *merged = malloc(size * sizeof(int));

	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
		{
			merged[k] = left[i];
			i++;
		}
		else
		{
			merged[k] = right[j];
			j++;
		}
		k++;
	}
	while (i < left_size)
	{
		merged[k] = left[i];
		i++;
		k++;
	}
	while (j < right_size)
	{
		merged[k] = right[j];
		j++;
		k++;
	}
	for (k = 0; k < size; k++)
		array[k] = merged[k];
	free(merged);
	printf("Result:\n");
	print_array(array, size);
}
