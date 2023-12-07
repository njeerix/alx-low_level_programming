#include "lists.h"
/**
 * sum_dlistint - Returns the sum of all the data (n) of a listint_t list.
 * @head: a pointer to the head of the doubly linked list.
 * Return: the sum all the data, or 0 if the list is empty.
 */
int sum_dlistint(dlistint_t *head)
{
int sum = 0;
dlistint_t *current = head;
while (current != NULL)
{
sum += current->n;
current = current->next;
}
return (sum);
}
