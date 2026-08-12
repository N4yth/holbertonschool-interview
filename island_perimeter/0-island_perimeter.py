#!/usr/bin/python3
"""
module that returns the perimeter of the island described in grid
"""


def island_perimeter(grid):
    """
    function that returns the perimeter of the island described in grid
    """
    perimeter = 0
    height = len(grid)
    width = len(grid[0])
    for row in range(0, height):
        for col in range(0, width):
            if grid[row][col] == 1:
                if col != 0 and grid[row][col - 1] == 0:
                    perimeter += 1
                if col != len(grid[row]) - 1 and grid[row][col + 1] == 0:
                    perimeter += 1
                if row != 0 and grid[row - 1][col] == 0:
                    perimeter += 1
                if row != len(grid) - 1 and grid[row + 1][col] == 0:
                    perimeter += 1 

    return perimeter
