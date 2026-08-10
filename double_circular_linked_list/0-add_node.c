#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/**
* add_node_begin - add a node at the beginning of the list
* @list: the list to modify
* @str: the string to add
*
* Return: NULL or the new node
*/
List *add_node_begin(List **list, char *str)
{
	List *new_node, *tmp;

	if (list == NULL)
		return (NULL);

	new_node = malloc(sizeof(*new_node));
	if (new_node == NULL)
		return (NULL);

	new_node->str = strdup(str);
	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}

	if (*list == NULL)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		*list = new_node;
		return (new_node);
	}

	tmp = (*list)->prev;
	new_node->next = *list;
	new_node->prev = tmp;
	tmp->next = new_node;
	(*list)->prev = new_node;
	*list = new_node;

	return (new_node);
}

/**
* add_node_end - add a node at the end of the list
* @list: the list to modify
* @str: the string to add
*
* Return: NULL or the new node
*/
List *add_node_end(List **list, char *str)
{
	List *new_node, *tmp;

	if (list == NULL)
		return (NULL);

	new_node = malloc(sizeof(*new_node));
	if (new_node == NULL)
		return (NULL);

	new_node->str = strdup(str);
	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}

	if (*list == NULL)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		*list = new_node;
		return (new_node);
	}

	tmp = (*list)->prev;
	new_node->next = *list;
	new_node->prev = tmp;
	tmp->next = new_node;
	(*list)->prev = new_node;

	return (new_node);
}
