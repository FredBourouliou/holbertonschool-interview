#include <stdio.h>
#include "search_algos.h"

/**
 * print_array - Prints an array of integers
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 */
void print_array(int *array, size_t size)
{
	size_t i;

	printf("Searching in array: ");
	for (i = 0; i < size; i++)
	{
		printf("%d", array[i]);
		if (i < size - 1)
			printf(", ");
	}
	printf("\n");
}

/**
 * binary_recursive - Recursive helper for advanced binary search
 * @array: Pointer to the first element of the subarray
 * @size: Number of elements in the subarray
 * @value: Value to search for
 * @offset: Offset from the original array start
 *
 * Return: Index of first occurrence of value, or -1 if not found
 */
int binary_recursive(int *array, size_t size, int value, size_t offset)
{
	size_t mid;
	int result;

	if (size == 0)
		return (-1);

	print_array(array, size);

	mid = (size - 1) / 2;

	if (array[mid] == value)
	{
		if (mid == 0)
			return ((int)(offset + mid));
		result = binary_recursive(array, mid + 1, value, offset);
		if (result != -1)
			return (result);
		return ((int)(offset + mid));
	}

	if (array[mid] < value)
		return (binary_recursive(array + mid + 1, size - mid - 1,
					value, offset + mid + 1));

	return (binary_recursive(array, mid, value, offset));
}

/**
 * advanced_binary - Searches for a value in a sorted array of integers
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in array
 * @value: Value to search for
 *
 * Return: Index of first occurrence of value, or -1 if not found or NULL array
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (binary_recursive(array, size, value, 0));
}
