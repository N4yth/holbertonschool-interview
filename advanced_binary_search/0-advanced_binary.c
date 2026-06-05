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
 * advanced_binary - Searches for the FIRST occurrence of a value
 *                   in a sorted array of integers using recursion
 *
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in @array
 * @value: The value to search for
 *
 * Return: Index of the first occurrence of @value, or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
    int result;
    size_t mid;

    if (array == NULL || size == 0)
        return (-1);

    print_array(array, size);

    /* Base case: single element */
    if (size == 1)
        return (array[0] == value ? 0 : -1);

    mid = size / 2;

    if (array[mid] == value)
    {
        if (mid > 0 && array[mid - 1] == value)
        {
            result = advanced_binary(array, mid, value);
            return (result == -1 ? (int)mid : result);
        }
        result = advanced_binary(array + mid, size - mid, value);
        return ((int)mid + (result == -1 ? 0 : result));
    }

	if (array[0] == value)
		return (-1);

    if (array[mid] > value)
        return (advanced_binary(array, mid, value));

    result = advanced_binary(array + mid + 1, size - mid - 1, value);
    if (result == -1)
        return (-1);
    return ((int)mid + 1 + result);
}
