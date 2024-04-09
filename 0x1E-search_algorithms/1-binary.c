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
	size_t left = 0, right = size - 1, mid;

	if (array == NULL)
		return (-1);

	while (left <= right)
	{
		print_array(array, left, right);

		mid = (left + right) / 2;

		if (array[mid] == value)
			return (mid);

		else if (array[mid] < value)
			left = mid + 1;
		else
			right = mid - 1;
	}

	return (-1);
}
/**
 * print_array - prints an array of integers within a given range
 * @array: Pointer to the first element of the array
 * @start: Start index of the subarray to print
 * @end: End index of the subarray to print
 */
void print_array(int *array, size_t start, size_t end)
{
	size_t i;

	printf("Search in array: ");
	for (i = start; i <= end; i++)
	{
		printf("%d", array[i]);
		if (i < end)
			printf(", ");
	}
	printf("\n");
}
