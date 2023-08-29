#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
/**
 * print_listint - Prints all the elements of a listint_t list.
 * @h: Pointer to the head of the list.
 * Return: Number of nodes in the list.
 */
size_t print_listint(const listint_t *h)
{
const listint_t *current;
size_t count = 0;
current = h;
while (current)
{
printf("%d\n", current->n);
count++;
current = current->next;
}
return (count);
}
