#include <stdio.h>
#include "sandpiles.h"

/**
 * print_grid - print the sand pile
 *
 * @grid: the sand pile
 *
 * Return: nothing
 */
static void print_grid(int grid[3][3])
{
	int row, col;

	for (row = 0; row < 3; row++)
	{
		for (col = 0; col < 3; col++)
		{
			if (col)
				printf(" ");
			printf("%d", grid[row][col]);
		}
		printf("\n");
	}
}

/**
 * is_stable - test if a sandpile is stable
 *
 * @grid: the sand pile
 *
 * Return: true of false
 */
static int is_stable(int grid[3][3])
{
	int row, col;

	for (row = 0; row < 3; row++)
		for (col = 0; col < 3; col++)
			if (grid[row][col] > 3)
				return (0);
	return (1);
}

/**
 * sandpiles_sum - sum 2 pile of sand
 *
 * @grid1: the first sand pile
 * @grid2: the second sand pile
 *
 * Return: nothing
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int row, col;
	int temp[3][3];

	for (row = 0; row < 3; row++)
		for (col = 0; col < 3; col++)
			grid1[row][col] += grid2[row][col];

	while (!is_stable(grid1))
	{
		printf("=\n");
		print_grid(grid1);
		for (row = 0; row < 3; row++)
			for (col = 0; col < 3; col++)
				temp[row][col] = grid1[row][col];
		for (row = 0; row < 3; row++)
		{
			for (col = 0; col < 3; col++)
			{
				if (grid1[row][col] > 3)
				{
					temp[row][col] -= 4;

					if (row > 0)
						temp[row - 1][col] += 1;
					if (row < 2)
						temp[row + 1][col] += 1;
					if (col > 0)
						temp[row][col - 1] += 1;
					if (col < 2)
						temp[row][col + 1] += 1;
				}
			}
		}
		for (row = 0; row < 3; row++)
			for (col = 0; col < 3; col++)
				grid1[row][col] = temp[row][col];
	}
}
