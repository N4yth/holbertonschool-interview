#include "lists.h"

/**
 * check_cycle - test if linked list have cycle
 *
 * @list: list
 *
 * Return: true or false
 */
int check_cycle(listint_t *list)
{
	listint_t *slow, *fast;

	if (!list)
		return (0);
	slow = list;
	fast = list;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			return (1);
	}
	return (0);
}
