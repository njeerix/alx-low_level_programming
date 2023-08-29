#include <stdio.h>
#include "lists.h"
/**
 * print_listint_safe - Prints a listint_t linked list safely.
 * @head: Pointer to the head of the list.
 * Return: The number of nodes int the list.
 */
size_t print_listint_safe(const listint_t *head)
{
size_t count = 0;
const listint_t *current = head, *loop_node = NULL;
while (current != NULL)
{
printf("[%p] %d\n", (void *)current, current->n);
if (count > 0 && current == loop_node)
{
printf("-> [%p] %d\n", (void *)current, current->n);
break;
}
if (count == 0)
loop_node = current;
current = current->next;
count++;
}
return (count);
}
