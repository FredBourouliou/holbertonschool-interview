#!/usr/bin/python3
"""
0-pascal_triangle

Provides a function that returns Pascal's triangle of a given size
as a list of lists of integers.
"""


def pascal_triangle(n):
    """Return Pascal's triangle of size ``n`` as a list of lists.

    Args:
        n (int): Number of rows of the triangle to generate.

    Returns:
        list[list[int]]: The Pascal's triangle, or an empty list if
        ``n`` is less than or equal to zero.
    """
    if n <= 0:
        return []

    triangle = [[1]]
    for i in range(1, n):
        previous = triangle[i - 1]
        row = [1]
        for j in range(1, i):
            row.append(previous[j - 1] + previous[j])
        row.append(1)
        triangle.append(row)
    return triangle
