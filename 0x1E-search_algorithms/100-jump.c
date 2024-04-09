#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "search_algos.h"
/**
 * jump_search - Searches for a value in a sorted array of integeres using
 * Jump search
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: Index of the value in the array, or -1 if not found
 */
int jump_search(int *array, size_t size, int value)
{
	size_t step;
	size_t prev = 0;
	size_t start;
	size_t i;

	if (array == NULL || size == 0)
		return (-1);

	step = (size_t)sqrt((double)size);

	while (array[prev] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);

		prev += step;

		if (prev >= size)
			break;
	}

	start = prev - step;
	printf("Value found between indexes [%lu] and [%lu]\n", start, prev);

	for (i = start; i <= prev && i < size; i++)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
	}

	return (-1);
}
