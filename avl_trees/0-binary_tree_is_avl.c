#include <stdlib.h>
#include <stddef.h>
#include <limits.h>
#include "binary_trees.h"

/**
 * avl_helper - Checks recursively if a tree is a valid BST
 *
 * @tree: Pointer to the node to check
 * @min: Lower bound for valid values in this subtree
 * @max: Upper bound for valid values in this subtree
 *
 * Return: The height of the subtree if it is a AVL subtree or -1 if it is not
 * 
 */
static int avl_helper(const binary_tree_t *tree, int min, int max)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);
	if (tree->n <= min || tree->n >= max)
		return (-1);
	left_height = avl_helper(tree->left, min, tree->n);
	if (left_height == -1)
		return (-1);
	right_height = avl_helper(tree->right, tree->n, max);
	if (right_height == -1)
		return (-1);
	if (abs(left_height - right_height) > 1)
		return (-1);

	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a AVL Tree
 *
 * @tree: Pointer to the root of the tree
 *
 * Return: 1 if tree is a AVL Tree, otherwise 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (avl_helper(tree, INT_MIN, INT_MAX) != -1);
}
