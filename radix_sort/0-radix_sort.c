#include <stdlib.h>
#include "sort.h"

/**
* radix_sort - sorts an array using LSD radix sort
*
* @array: array to sort
* @size: size of the array
*
* Return : Nothing
*/
void radix_sort(int *array, size_t size)
{
	int *output;
	int count[10];
	int max;
	int digit;
	int i;
	int exp;

	if (array == NULL || size < 2)
		return;
	output = malloc(sizeof(int) * size);
	if (output == NULL)
		return;
	max = array[0];
	for (i = 1; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	for (exp = 1; max / exp > 0; exp *= 10)
	{
		for (i = 0; i < 10; i++)
			count[i] = 0;
		for (i = 0; i < (int)size; i++)
		{
			digit = (array[i] / exp) % 10;
			count[digit]++;
		}
		for (i = 1; i < 10; i++)
			count[i] += count[i - 1];
		for (i = (int)size - 1; i >= 0; i--)
		{
			digit = (array[i] / exp) % 10;
			output[count[digit] - 1] = array[i];
			count[digit]--;
		}
		for (i = 0; i < (int)size; i++)
			array[i] = output[i];
		print_array(array, size);
	}
	free(output);
}
