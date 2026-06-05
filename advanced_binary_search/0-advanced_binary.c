#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
	size_t i = 0;

	printf("Searching in array: ");
	while (array && i < size)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
		++i;
	}
	printf("\n");
}

/**
 * advanced_binary_recursive - Recursive helper for advanced_binary
 * @array: Pointer to the first element of the subarray
 * @left: Left (start) index relative to the original array
 * @size: Number of elements in the current subarray
 * @value: Value to search for
 *
 * Return: Index of the first occurrence of value, or -1 if not found
 */
static int advanced_binary_recursive(int *array, size_t left, size_t size, int value)
{
    size_t mid;

    if (!array || size == 0)
        return (-1);

    print_array(array, size);

    mid = (size - 1) / 2;

    /* If value found at mid, check if it's the FIRST occurrence */
    if (array[mid] == value)
    {
        /* If it's the first element or the previous one differs, we found it */
        if (mid == 0 || array[mid - 1] != value)
            return ((int)(left + mid));
        /* Otherwise, search in the left half (including mid) */
        return (advanced_binary_recursive(array, left, mid + 1, value));
    }

    if (array[mid] > value)
        /* Search left half */
        return (advanced_binary_recursive(array, left, mid, value));

    /* Search right half */
    return (advanced_binary_recursive(array + mid + 1, left + mid + 1,
                                      size - mid - 1, value));
}

/**
 * advanced_binary - Searches for a value in a sorted array of integers
 *                   and returns the index of the FIRST occurrence
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in array
 * @value: Value to search for
 *
 * Return: Index of the first occurrence of value, or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
    if (!array || size == 0)
        return (-1);

    return (advanced_binary_recursive(array, 0, size, value));
}
