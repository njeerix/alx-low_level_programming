#include <stdlib.h>
#include "../search_algos.h"
/**
 * free_list - Frees a singly linked list
 *
 * @list: Pointer to the head of the linked list
 */
void free_list(listint_t *list)
{
	listint_t *temp;

	while (list != NULL)
	{
		temp = list;
		list = list->next;
		free(temp);
	}
}
/**
 * create_list - Creates a singly linked list from an array of integers
 *
 * @array: Pointer to the array of integers
 * @size: Size of the array
 *
 * Return: A pointer to the head of the created list, or NULL on failure
 */
listint_t *create_list(int *array, size_t size)
{
	listint_t *list = NULL;
	listint_t *node = NULL;
	size_t i;

	for (i = 0; i < size; i++)
	{
		node = malloc(sizeof(*node));
		if (node == NULL)
		{
			free_list(list);
			return (NULL);
		}

		node->n = array[i];
		node->index = i;
		node->next = NULL;

		if (list == NULL)
		{
			list = node;
		}
		else
		{
			node->next = list;
			list = node;
		}
	}

	return (list);
}
