#include <stdlib.h>
#include "sort.h"

/**
 * getMax - Get the maximum value in an array
 * @array: The array to search
 * @size: The size of the array
 * Return: The maximum value
 */
int getMax(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * countingSort - Perform counting sort on the specified digit
 * @array: The array to be sorted
 * @size: The size of the array
 * @exp: The current digit position (1, 10, 100, ...)
 */
void countingSort(int *array, size_t size, int exp)
{
	int *output = malloc(sizeof(int) * size);
	int count[10] = {0};
	size_t i;

	if (output == NULL)
		exit(EXIT_FAILURE);
	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (i = size - 1; i > 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(output);
}

/**
 * radix_sort - LSD Radix Sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max = getMax(array, size);
	size_t exp;

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		countingSort(array, size, exp);
		print_array(array, size);
	}
}
