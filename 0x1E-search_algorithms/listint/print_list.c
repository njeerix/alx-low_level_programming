#include <stdio.h>
#include "../search_algos.h"
/**
 * print_list - Prints the contents of a linked list
 *
 * @list: Pointer to the head of the linked list
 */
void print_list(const listint_t *list)
{
	const listint_t *current = list;

	printf("List :\n");
	while (current != NULL)
	{
		printf("Index[%lu] = [%d]\n", current->index, current->n);
		current = current->next;
	}
	printf("\n");
}
