#include "binary_trees.h"
#include <stdlib.h>

/**
 * tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Size of the tree, 0 if tree is NULL
 */
size_t tree_size(const heap_t *tree)
{
	if (!tree)
		return (0);

	return (1 + tree_size(tree->left) + tree_size(tree->right));
}

/**
 * get_last_node - Gets the last node in level-order traversal
 * @root: Pointer to the root node
 * @size: Total number of nodes in the tree
 *
 * Return: Pointer to the last node
 */
heap_t *get_last_node(heap_t *root, size_t size)
{
	size_t bit;

	if (size == 1)
		return (root);

	/* Find the highest bit position */
	for (bit = 1; bit <= size; bit <<= 1)
		;
	bit >>= 2;

	/* Navigate using binary representation of size */
	while (bit > 0)
	{
		if (size & bit)
			root = root->right;
		else
			root = root->left;
		bit >>= 1;
	}

	return (root);
}

/**
 * heapify_down - Restores the max heap property by sifting down
 * @node: Pointer to the node to start heapifying from
 */
void heapify_down(heap_t *node)
{
	heap_t *largest;
	int temp;

	while (node)
	{
		largest = node;

		if (node->left && node->left->n > largest->n)
			largest = node->left;

		if (node->right && node->right->n > largest->n)
			largest = node->right;

		if (largest == node)
			break;

		/* Swap values */
		temp = node->n;
		node->n = largest->n;
		largest->n = temp;

		node = largest;
	}
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 *
 * Return: Value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
	int extracted_value;
	size_t size;
	heap_t *last_node;

	if (!root || !*root)
		return (0);

	extracted_value = (*root)->n;
	size = tree_size(*root);

	if (size == 1)
	{
		free(*root);
		*root = NULL;
		return (extracted_value);
	}

	/* Get the last node in level-order */
	last_node = get_last_node(*root, size);

	/* Replace root value with last node's value */
	(*root)->n = last_node->n;

	/* Remove last node from tree */
	if (last_node->parent->right == last_node)
		last_node->parent->right = NULL;
	else
		last_node->parent->left = NULL;

	free(last_node);

	/* Restore heap property */
	heapify_down(*root);

	return (extracted_value);
}
