#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"
/**
 * binary_search - Searches for a value in sorted array of integers using
 * binary search
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: Index of the value in the array, or -1 if not found
 */
int binary_search(int *array, size_t size, int value)
{
	size_t left = 0;
	size_t right = size - 1;
	size_t mid;

	while (left <= right)
	{
		mid = left + (right + left) / 2;

		printf("Searching in array: ");

		if (array[mid] == value)
			return (mid);
		else if (array[mid] < value)
			left = mid + 1;
		else
			right = mid - 1;
	}

	return (-1);
}
