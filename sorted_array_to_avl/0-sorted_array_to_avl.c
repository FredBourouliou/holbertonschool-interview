#include "binary_trees.h"
#include <stdlib.h>

/**
 * create_node - Creates a new AVL tree node
 * @parent: Pointer to the parent node
 * @value: Value to store in the node
 *
 * Return: Pointer to the new node, or NULL on failure
 */
avl_t *create_node(avl_t *parent, int value)
{
	avl_t *node;

	node = malloc(sizeof(avl_t));
	if (node == NULL)
		return (NULL);

	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

/**
 * build_avl_tree - Recursively builds an AVL tree from sorted array
 * @parent: Pointer to the parent node
 * @array: Pointer to the first element of the array
 * @start: Starting index of the subarray
 * @end: Ending index of the subarray
 *
 * Return: Pointer to the root node of the subtree, or NULL on failure
 */
avl_t *build_avl_tree(avl_t *parent, int *array, int start, int end)
{
	avl_t *node;
	int mid;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	node = create_node(parent, array[mid]);
	if (node == NULL)
		return (NULL);

	node->left = build_avl_tree(node, array, start, mid - 1);
	node->right = build_avl_tree(node, array, mid + 1, end);

	return (node);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);

	return (build_avl_tree(NULL, array, 0, (int)size - 1));
}
