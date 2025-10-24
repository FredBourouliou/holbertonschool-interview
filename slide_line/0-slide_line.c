#include "slide_line.h"

/**
 * compact_left - Moves all non-zero elements to the left
 * @line: Pointer to array of integers
 * @size: Number of elements in the array
 */
static void compact_left(int *line, size_t size)
{
	size_t i, j = 0;

	for (i = 0; i < size; i++)
	{
		if (line[i] != 0)
		{
			if (i != j)
			{
				line[j] = line[i];
				line[i] = 0;
			}
			j++;
		}
	}
}

/**
 * merge_left - Merges adjacent identical numbers from left to right
 * @line: Pointer to array of integers
 * @size: Number of elements in the array
 */
static void merge_left(int *line, size_t size)
{
	size_t i;

	for (i = 0; i < size - 1; i++)
	{
		if (line[i] != 0 && line[i] == line[i + 1])
		{
			line[i] *= 2;
			line[i + 1] = 0;
			i++;
		}
	}
}

/**
 * compact_right - Moves all non-zero elements to the right
 * @line: Pointer to array of integers
 * @size: Number of elements in the array
 */
static void compact_right(int *line, size_t size)
{
	size_t i;
	int j;

	if (size == 0)
		return;

	j = (int)size - 1;

	for (i = size; i > 0; i--)
	{
		if (line[i - 1] != 0)
		{
			if ((int)(i - 1) != j)
			{
				line[j] = line[i - 1];
				line[i - 1] = 0;
			}
			j--;
		}
	}
}

/**
 * merge_right - Merges adjacent identical numbers from right to left
 * @line: Pointer to array of integers
 * @size: Number of elements in the array
 */
static void merge_right(int *line, size_t size)
{
	size_t i;

	if (size == 0)
		return;

	for (i = size - 1; i > 0; i--)
	{
		if (line[i] != 0 && line[i] == line[i - 1])
		{
			line[i] *= 2;
			line[i - 1] = 0;
			i--;
		}
	}
}

/**
 * slide_line - Slides and merges an array of integers
 * @line: Pointer to array of integers
 * @size: Number of elements in the array
 * @direction: Direction to slide (SLIDE_LEFT or SLIDE_RIGHT)
 *
 * Return: 1 on success, 0 on failure
 */
int slide_line(int *line, size_t size, int direction)
{
	if (!line)
		return (0);

	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);

	if (size == 0)
		return (1);

	if (direction == SLIDE_LEFT)
	{
		compact_left(line, size);
		merge_left(line, size);
		compact_left(line, size);
	}
	else
	{
		compact_right(line, size);
		merge_right(line, size);
		compact_right(line, size);
	}

	return (1);
}
