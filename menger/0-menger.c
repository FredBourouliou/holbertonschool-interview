#include "menger.h"
#include <stdio.h>
#include <math.h>

/**
 * menger - draws a 2D Menger sponge
 * @level: level of the Menger Sponge to draw
 *
 * Description: Draws a 2D Menger sponge of the specified level.
 * A level N sponge is a 3x3 square of level N-1 sponges, except
 * for the center one, which is left empty.
 * The size of a level N Menger sponge is 3^N.
 *
 * Return: void
 */
void menger(int level)
{
	int size, row, col, r, c, s;
	int is_hole;

	if (level < 0)
		return;

	size = pow(3, level);

	for (row = 0; row < size; row++)
	{
		for (col = 0; col < size; col++)
		{
			is_hole = 0;
			r = row;
			c = col;
			s = size;

			/* Check if position is in a hole at any scale */
			while (s > 1)
			{
				/* If in center of 3x3 block at this scale, it's a hole */
				if (r % 3 == 1 && c % 3 == 1)
				{
					is_hole = 1;
					break;
				}
				/* Move to next scale level */
				r /= 3;
				c /= 3;
				s /= 3;
			}

			if (is_hole)
				printf(" ");
			else
				printf("#");
		}
		printf("\n");
	}
}
