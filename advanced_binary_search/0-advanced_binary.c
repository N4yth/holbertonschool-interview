#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "search_algos.h"

/**
 * advanced_binary - Function that searches for a value in a sorted array of integers
 *
 * @array: array to sort
 * @size: size of array
 * @value: the value to search
 * 
 * Return : The index of the value found
*/
int advanced_binary(int *array, size_t size, int value)
{
	int result;
	int mid = 0;
	if (array == NULL || size == 0)
	{
		return (-1);
	}

	print_array(array, size);

	if (array[0] == value)
	{
		return(0);
	}
	if(size % 2 == 1)
		mid = size / 2 + 1;
	else
		mid = size / 2;
	if (array[size / 2] < value)
		{
			result = advanced_binary(&array[mid], size / 2, value);
			if (result == -1)
				return (-1);
			return (mid + result);
		}
	return(advanced_binary(&array[0], size / 2, value));
}

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
*/
void print_array(const int *array, size_t size)
{
	size_t i;
	printf("Searching in array: ");
	i = 0;
	while (array && i < size)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
		++i;
	}
	printf("\n");
}
