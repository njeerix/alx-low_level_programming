#include <stdio.h>
#include "search_algos.h"
/**
 * advanced_binary - Searches for the first occurrence of a value in a sorted
 * array of integers using binary search.
 * @array: Pointer to the first elemnt of the array
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: Index of the first occurrence of value in array, or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
	size_t mid, i;
	int index;

	if (array == NULL || size == 0)
		return (-1);

	printf("Searching in array:");
	for (i = 0; i < size; i++)
	{
		if (i != 0)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");

	mid = (size - 1) / 2;

	if (array[mid] == value)
	{
		if (mid == 0 || array[mid - 1] < value)
			return (mid);
	}

	if (array[mid] >= value)
		return (advanced_binary(array, mid + 1, value));

	index = advanced_binary(array + mid + 1, size - mid - 1, value);
	if (index == -1)
		return (-1);
	return (mid + 1 + index);
}
