#include "sort.h"
#include <stdio.h>

/**
 * swap - swap two integers
 * @a: first integer
 * @b: second integer
 */
void swap(int *a, int *b)
{
	int tmp = *a;

	*a = *b;
	*b = tmp;
}

/**
 * sift_down - maintain heap property
 * @array: array to sort
 * @size: total size of array
 * @root: current root index
 * @end: last index of heap
 */
void sift_down(int *array, size_t size, size_t root, size_t end)
{
	size_t child, swap_idx;

	while ((root * 2 + 1) <= end)
	{
		child = root * 2 + 1;
		swap_idx = root;
		if (array[swap_idx] < array[child])
			swap_idx = child;
		if (child + 1 <= end &&
			array[swap_idx] < array[child + 1])
			swap_idx = child + 1;
		if (swap_idx == root)
			return;
		swap(&array[root], &array[swap_idx]);
		print_array(array, size);
		root = swap_idx;
	}
}

/**
 * heap_sort - sorts an array using Heap sort
 * @array: array to sort
 * @size: size of array
 */
void heap_sort(int *array, size_t size)
{
	ssize_t start;
	size_t end;

	if (!array || size < 2)
		return;

	start = (size / 2) - 1;
	while (start >= 0)
	{
		sift_down(array, size, start, size - 1);
		start--;
	}
	end = size - 1;
	while (end > 0)
	{
		swap(&array[end], &array[0]);
		print_array(array, size);
		end--;
		sift_down(array, size, 0, end);
	}
}
