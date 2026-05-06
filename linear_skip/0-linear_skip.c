#include <stdio.h>
#include "search.h"

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *prev = list;

	if (!list)
		return (NULL);
	while (list->express)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			list->express->index, list->express->n);
		if (list->express->n >= value)
			break;
		list = list->express;
	}
	prev = list;
	if (list->express)
	{
		printf("Value found between indexes [%lu] and [%lu]\n",
			list->index, list->express->index);
		list = list->express;
	}
	else
	{
		skiplist_t *tail = list;

		while (tail->next)
			tail = tail->next;
		printf("Value found between indexes [%lu] and [%lu]\n",
			list->index, tail->index);
		list = tail;
	}
	while (prev && prev->index <= list->index)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			prev->index, prev->n);
		if (prev->n == value)
			return (prev);
		prev = prev->next;
	}
	return (NULL);
}
