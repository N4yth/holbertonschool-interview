#include "lists.h"
#include <stdlib.h>
/**
 * add_node - the function create a new head on a linked list
 *
 * @head: the head of the linked list
 * @str: the string of the new head
 *
 * Return: the new head node
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node;
	listint_t *current;

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = number;

	if (*head == NULL || (*head)->n >= number)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}

	current = *head;

	while (current->next != NULL && current->next->n < number)
		current = current->next;

	new_node->next = current->next;
	current->next = new_node;

	return (new_node);
}