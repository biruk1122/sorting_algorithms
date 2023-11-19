#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/* Function Prototypes */
void heapify(int *array, size_t size, size_t i);
void heap_sort(int *array, size_t size);

/**
 * heapify - Heapifies a subtree rooted with the given index
 * @array: The array to be sorted
 * @size: The size of the array
 * @i: The index of the root of the subtree to be heapified
 */
void heapify(int *array, size_t size, size_t i)
{
	size_t largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < (int)size && array[left] > array[largest])
		largest = left;

	if (right < (int)size && array[right] > array[largest])
		largest = right;
	if (largest != i)
	{
		int temp = array[i];

		array[i] = array[largest];
		array[largest] = temp;
		print_array(array, size);
		heapify(array, size, largest);
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap sort
 * @array: The array to be sorted
 * @size: The size of the array
 */
void heap_sort(int *array, size_t size)
{
	size_t i;

	for (i = size / 2 - 1; i < size; i--)
		heapify(array, size, i);
	for (i = size - 1; i > 0; i--)
	{
		int temp = array[0];

		array[0] = array[i];
		array[i] = temp;
		print_array(array, size);
		heapify(array, i, 0);
	}
}
