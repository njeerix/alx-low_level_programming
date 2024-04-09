#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "search_algos.h"
/**
 * jump_list - Searches for a value in a sorted list of integers using the Jump
 * search algorithm
 * @list: Pointer to the head of the list to search in
 * @size: Number of nodes in the list (not actually used for this function)
 * @value: Value to search for
 *
 * Return: Pointer to the first node where value is located, or NULL if not found
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t step = sqrt(size);
	listint_t *current, *prev;

	if (list == NULL)
		return (NULL);

	current = list;
	while (current != NULL && current->n < value)
	{
		prev = current;
		for (size_t i = 0; i < step && current->next != NULL; i++)
			current = current->next;

		printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
		if (prev->n == value)
			return (prev);
		prev = prev->next;
	}

	return (NULL);
}
