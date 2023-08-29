#include <stddef.h>
#include "lists.h"
/**
 * find_listint_loop - Finds the start of a loop in a linked list.
 * @head: Pointer to the head of the list.
 * Return: The address of the node where the loop starts, or NULL if there is no loop.
 */
listint_t *find_listint_loop(listint_t *head)
{
listint_t *tortoise, *hare;
if (head == NULL || head->next == NULL)
return (NULL);
tortoise = head;
hare = head;
while (tortoise && hare && hare->next)
{
tortoise = tortoise->next;
hare = hare->next->next;
if (tortoise == hare)
{
tortoise = head;
while (tortoise != hare)
{
tortoise = tortoise->next;
hare = hare->next;
}
return (hare);
}
}
return (NULL);
}
