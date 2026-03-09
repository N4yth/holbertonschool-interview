#include "lists.h"

/**
 * reverse_list - reverses a list
 *
 * @head: head
 *
 * Return: new head
 */
listint_t *reverse_list(listint_t *head)
{
	listint_t *prev = NULL, *next = NULL;

	while (head)
	{
		next = head->next;
		head->next = prev;
		prev = head;
		head = next;
	}

	return (prev);
}

/**
 * is_palindrome - test if list is a palindrom
 *
 * @head: pointer to pointer to head
 *
 * Return: true or false
 */
int is_palindrome(listint_t **head)
{
	listint_t *slow, *fast, *second_half, *copy_head;

	if (!head || !*head || !(*head)->next)
		return (1);

	slow = *head;
	fast = *head;

	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	second_half = reverse_list(slow);
	copy_head = *head;
	while (second_half)
	{
		if (copy_head->n != second_half->n)
			return (0);

		copy_head = copy_head->next;
		second_half = second_half->next;
	}

	return (1);
}
