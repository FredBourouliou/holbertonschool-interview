#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * merge - merges two sorted sub-arrays into one
 * @array: the original array
 * @tmp: temporary buffer
 * @lo: start index of left sub-array
 * @mid: end index of left sub-array (exclusive) / start of right
 * @hi: end index of right sub-array (exclusive)
 */
static void merge(int *array, int *tmp, size_t lo, size_t mid, size_t hi)
{
	size_t i, l, r;

	printf("Merging...\n[left]: ");
	print_array(array + lo, mid - lo);
	printf("[right]: ");
	print_array(array + mid, hi - mid);

	for (i = lo; i < hi; i++)
		tmp[i] = array[i];

	l = lo;
	r = mid;
	for (i = lo; i < hi; i++)
	{
		if (l < mid && (r >= hi || tmp[l] <= tmp[r]))
			array[i] = tmp[l++];
		else
			array[i] = tmp[r++];
	}

	printf("[Done]: ");
	print_array(array + lo, hi - lo);
}

/**
 * split - recursively splits and sorts the array
 * @array: the array to sort
 * @tmp: temporary buffer
 * @lo: start index (inclusive)
 * @hi: end index (exclusive)
 */
static void split(int *array, int *tmp, size_t lo, size_t hi)
{
	size_t mid;

	if (hi - lo < 2)
		return;

	mid = lo + (hi - lo) / 2;
	split(array, tmp, lo, mid);
	split(array, tmp, mid, hi);
	merge(array, tmp, lo, mid, hi);
}

/**
 * merge_sort - sorts an array of integers using top-down merge sort
 * @array: the array to sort
 * @size: number of elements in the array
 */
void merge_sort(int *array, size_t size)
{
	int *tmp;

	if (!array || size < 2)
		return;

	tmp = malloc(sizeof(int) * size);
	if (!tmp)
		return;

	split(array, tmp, 0, size);
	free(tmp);
}
