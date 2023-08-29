#include <stdlib.h>
#include "lists.h"
/**
 * pop_listint - Deletes the head node of a listint_t linked list.
 * @head: Pointer to the pointer of the head of the list.
 * Return: The data (n) of the deleted head node, or 0 if the list is empty.
 */
int pop_listint(listint_t **head)
{
listint_t *current;
int data = 0;
if (*head == NULL)
return (0);
current = *head;
*head = (*head)->next;
data = current->n;
free(current);
return (data);
}
