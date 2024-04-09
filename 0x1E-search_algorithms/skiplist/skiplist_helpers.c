#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../search_algos.h"
/**
 * create_skiplist - Creates a skip list from an array of integers
 *
 * @array: Pointer to the array of integers
 * @size: Size of the array
 *
 * Return: Apointer to the head of the created skip list, or NULL on failure
 */
skiplist_t *create_skiplist(int *array, size_t size)
{
	skiplist_t *list = NULL, *node = NULL, *express = NULL;
	size_t i, express_step;

	if (array == NULL || size == 0)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		node = malloc(sizeof(skiplist_t));
		if (node == NULL)
		{
			free_skiplist(list);
			return (NULL);
		}
		node->n = array[i];
		node->index = i;
		node->next = NULL;

		if (i == 0 || i % express_step == 0)
		{
			if (express != NULL)
				express->express = node;
			express = node;
			express_step = sqrt(i + 1);
		}

		if (list == NULL)
			list = node;
		else
		{
			skiplist_t *temp = list;
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = node;
		}
	}

	return (list);
}

/**
 * print_skiplist - Prints the elements of a skip list
 *
 * @list: Pointer to the head of the skip list
 */
void print_skiplist(const skiplist_t *list)
{
	const skiplist_t *current = list;

	printf("List :\n");
	while (current != NULL)
	{
		printf("Index[%lu] = [%d]\n", current->index, current->n);
		current = current->next;
	}
	printf("\n");
}

/**
 * free_skiplist - Frees a skip list and its nodes
 *
 * @list: Pointer to the head of the skip list
 */
void free_skiplist(skiplist_t *list)
{
	skiplist_t *node;

	while (list != NULL)
	{
		node = list;
		list = list->next;
		free(node);
	}
}
