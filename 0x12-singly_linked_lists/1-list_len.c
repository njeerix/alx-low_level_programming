#include "lists.h"
/**
 * list_len - Return the number of elements in a list_t list.
 * @h: A pointer to the head of the list.
 * Return: The number of nodes in the list.
 */
size_t list_len(const list_t *h)
{
size_t count = 0;
const list_t *current = h;
while (current != NULL)
{
count++;
current = current->next;
}
return (count);
}
