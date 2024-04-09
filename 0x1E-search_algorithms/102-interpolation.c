#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"
/**
 * interpolation_search - Searches for a value in a sorted array of integeres
 * using Interpolation search
 * @array: Pointer to the first elelement of the array
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: Index of the value in the array, or -1 if not found
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t low = 0;
	size_t high = size - 1;
	size_t pos;
	size_t range;
	double factor;

	if (array == NULL || size == 0)
		return (-1);

	while (low <= high && value >= array[low] && value <= array[high])
	{
		range = array[high] - array[low];
		if (range == 0)
		{
			if (array[low] == value)
				return ((int)low);
		}

		factor = (double)(value - array[low]) / range;
		pos = low + (size_t)((high - low) * factor);

		printf("Value checked array[%lu] = [%d]\n", (unsigned long)pos, array[pos]);

		if (array[pos] == value)
			return ((int)pos);
		else if (array[pos] < value)
			low = pos + 1;
		else
			high = pos - 1;
	}

	printf("Value checked array[%lu] is out of range\n", (unsigned long)high);
	return (-1);
}
