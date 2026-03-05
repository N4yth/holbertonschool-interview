#include <string.h>
#include <stdlib.h>
#include <stdio.h>
/**
 * add_dnodeint - the function create a new head of a doubly linked list
 *
 * @head: the head of the doubly linked list
 * @n: the int of the new head
 *
 * Return: the new head of the doubly linked list
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new_head = malloc(sizeof(dlistint_t));

	if (new_head == NULL)
	{
		return (NULL);
	}

	new_head->n = n;
	new_head->prev = NULL;
	new_head->next = *head;

	if (*head != NULL)
	{
		(*head)->prev = new_head;
	}
	*head = new_head;
	return (*head);
}