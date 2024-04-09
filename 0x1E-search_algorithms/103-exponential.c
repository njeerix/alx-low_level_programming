#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"
/**
 * exponential_search - Searches for a value in a sorted array using
 * Exponential search
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: Index of the value in the array, or -1 if not found
 */
int exponential_search(int *array, size_t size, int value)
{
	int bound, low, high;

	if (array == NULL || size == 0)
		return (-1);

	bound = 1;

	while (bound < (int)size && array[bound] < value)
	{
		printf("Value checked array[%d] = [%d]\n", bound, array[bound]);
		bound *= 2;
	}

	low = bound / 2;
	high = (bound < (int)size) ? bound : (int)size - 1;

	printf("Value found between indexes [%d] and [%d]\n", low, high);

	return (binary_search(array, size, value));
}
