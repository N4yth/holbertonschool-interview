#include "binary_trees.h"
#include <stdlib.h>

/**
 * swap_int - swaps two integers
 */
static void swap_int(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * heapify_down - restores max heap property
 */
static void heapify_down(heap_t *node)
{
    heap_t *largest;
    heap_t *left;
    heap_t *right;

    while (node)
    {
        largest = node;
        left = node->left;
        right = node->right;

        if (left && left->n > largest->n)
            largest = left;
        if (right && right->n > largest->n)
            largest = right;

        if (largest == node)
            break;

        swap_int(&node->n, &largest->n);
        node = largest;
    }
}

/**
 * heap_extract - extracts root of max binary heap
 * @root: double pointer to root node
 *
 * Return: value stored at root, or 0 on failure
 */
int heap_extract(heap_t **root)
{
    heap_t *queue[1024];
    heap_t *last = NULL;
    heap_t *tmp;
    int value, i = 0, size = 0;

    if (!root || !*root)
        return (0);

    value = (*root)->n;

    if (!(*root)->left && !(*root)->right)
    {
        free(*root);
        *root = NULL;
        return (value);
    }
    queue[size++] = *root;

    while (i < size)
    {
        tmp = queue[i++];

        if (tmp->left)
            queue[size++] = tmp->left;
        if (tmp->right)
            queue[size++] = tmp->right;
    }

    last = queue[size - 1];

    (*root)->n = last->n;

    if (last->parent->left == last)
        last->parent->left = NULL;
    else
        last->parent->right = NULL;

    free(last);

    heapify_down(*root);

    return (value);
}
