#!/usr/bin/python3
"""Module that computes the perimeter of an island in a grid."""


def island_perimeter(grid):
    """Return the perimeter of the island described in grid.

    Args:
        grid: list of list of integers (0 = water, 1 = land).

    Returns:
        The perimeter of the island.
    """
    perimeter = 0
    rows = len(grid)
    cols = len(grid[0])

    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:
                perimeter += 4
                if i > 0 and grid[i - 1][j] == 1:
                    perimeter -= 2
                if j > 0 and grid[i][j - 1] == 1:
                    perimeter -= 2

    return perimeter
