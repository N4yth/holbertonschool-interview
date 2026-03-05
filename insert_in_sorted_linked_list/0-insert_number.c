#include "lists.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
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
    listint_t *new;
    listint_t *current;

    new = malloc(sizeof(listint_t));
    if (new == NULL)
        return (NULL);

    new->n = number;

    if (*head == NULL || (*head)->n >= number)
    {
        new->next = *head;
        *head = new;
        return (new);
    }

    current = *head;

    while (current->next != NULL && current->next->n < number)
        current = current->next;

    new->next = current->next;
    current->next = new;

    return (new);
}