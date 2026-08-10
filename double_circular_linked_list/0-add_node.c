#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/**
* add_node_begin - add a node at the begin of the list
*
* @list: the list to modify
* @str: the string to add
*
* Return: NULL or the new node
*/
List *add_node_begin(List **list, char *str);
	List *new_node, *tmp;


	if (*list == NULL)
		return NULL;

	new_node = malloc(sizeof(*new_node));
	if (new_node == NULL)
		return NULL;

	tmp = (*list)->prev
	new_node->next = *list;
	new_node->prev = tmp;
	tmp->next = new_node;
	(*list)->prev = new_node;
	new_node->str = str;
	*list = new_node;

	return new_node;

/**
* add_node_end - add a node at the end of the list
*
* @list: the list to modify
* @str: the string to add
*
* Return: NULL or the new node
*/
List *add_node_end(List **list, char *str);
	List *new_node, *tmp;

	if (*list == NULL)
		return NULL;

	new_node = malloc(sizeof(*new_node));
	if (new_node == NULL)
		return NULL;

	tmp = (*list)->prev
	new_node->next = (*list);
	new_node->prev = tmp;
	new_node->str = str;
	tmp->next = new_node;
	(*list)->prev = new_node;

	return new_node;
