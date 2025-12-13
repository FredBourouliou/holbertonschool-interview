#include "sort.h"

/**
 * swap - Swaps two integers and prints the array
 * @a: First integer
 * @b: Second integer
 * @array: The array to print
 * @size: Size of the array
 */
void swap(int *a, int *b, int *array, size_t size)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
	print_array(array, size);
}

/**
 * sift_down - Sifts down a node to maintain max-heap property
 * @array: The array representing the heap
 * @size: Total size of the array (for printing)
 * @heap_size: Current size of the heap
 * @root: Index of the node to sift down
 */
void sift_down(int *array, size_t size, size_t heap_size, size_t root)
{
	size_t largest, left, right;

	largest = root;
	left = 2 * root + 1;
	right = 2 * root + 2;

	if (left < heap_size && array[left] > array[largest])
		largest = left;

	if (right < heap_size && array[right] > array[largest])
		largest = right;

	if (largest != root)
	{
		swap(&array[root], &array[largest], array, size);
		sift_down(array, size, heap_size, largest);
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap sort
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	/* Build max heap */
	for (i = (size / 2) - 1; i >= 0; i--)
		sift_down(array, size, size, i);

	/* Extract elements from heap one by one */
	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i], array, size);
		sift_down(array, size, i, 0);
	}
}
