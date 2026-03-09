#include <stdio.h>
#include "sandpiles.h"

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

static int is_stable(int grid[3][3])
{
	int row, col;

	for (row = 0; row < 3; row++)
		for (col = 0; col < 3; col++)
			if (grid[row][col] > 3)
				return (0);
	return (1);
}

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
