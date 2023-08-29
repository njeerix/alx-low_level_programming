#include <stdlib.h>
#include "lists.h"
/**
 * insert_nodeint_at_index - Inserts a new node at a given position in a listint_t list.
 * @head: Pointer to the pointer of the head of the list.
 * @idx: Index where the new node should be added.
 * @n: Value to be assigned to the new node.
 * Return: Address of the new node, or NULL if it failed.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
listint_t *new_node, *current;
unsigned int count = 0;
new_node = malloc(sizeof(listint_t));
if (new_node == NULL)
return (NULL);
new_node->n = n;
if (idx == 0)
{
new_node->next = *head;
*head = new_node;
return (new_node);
}
current = *head;
while (current != NULL)
{
if (count == idx - 1)
{
new_node->next = current->next;
current->next = new_node;
return (new_node);
}
count++;
current = current->next;
}
free(new_node);
return (NULL);
}
