#include <stddef.h>
#include <stdlib.h>
#include "lists.h"
/**
 * free_listint_safe - Frees a listint_t linked list safely.
 * @h: Pointer to the head of the head of the list.
 * Return: The number of nodes in the list.
 */
size_t free_listint_safe(listint_t **h)
{
size_t count = 0;
listint_t *current = *h, *next;
listint_t *original_h = *h;
while (current != NULL)
{
count++;
next = current->next;
free(current);
current = next;
if (current == original_h)
break;
}
*h = NULL;
return (count);
}
