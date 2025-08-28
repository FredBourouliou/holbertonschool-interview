#include "binary_trees.h"

/**
 * heap_size - Calculates the size of the heap
 * @root: Pointer to the root node
 *
 * Return: Size of the heap
 */
size_t heap_size(heap_t *root)
{
	if (root == NULL)
		return (0);

	return (1 + heap_size(root->left) + heap_size(root->right));
}

/**
 * tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Height of tree, 0 if tree is NULL
 */
size_t tree_height(const heap_t *tree)
{
	size_t left_height = 0;
	size_t right_height = 0;

	if (!tree)
		return (0);

	left_height = tree->left ? 1 + tree_height(tree->left) : 0;
	right_height = tree->right ? 1 + tree_height(tree->right) : 0;

	return (left_height > right_height ? left_height : right_height);
}

/**
 * find_parent - Finds the parent node for the new node
 * @root: Pointer to the root node
 *
 * Return: Pointer to the parent node
 */
heap_t *find_parent(heap_t *root)
{
	heap_t *parent = NULL;
	size_t left_h, right_h;
	size_t left_s;

	if (!root)
		return (NULL);

	left_h = tree_height(root->left);
	right_h = tree_height(root->right);
	left_s = heap_size(root->left);

	if (!root->left || !root->right)
		return (root);

	if (left_h == right_h)
	{
		if ((1 << left_h) - 1 == (int)left_s)
			parent = find_parent(root->right);
		else
			parent = find_parent(root->left);
	}
	else
	{
		parent = find_parent(root->left);
	}

	return (parent);
}

/**
 * swap_values - Swaps values of two nodes
 * @node1: First node
 * @node2: Second node
 */
void swap_values(heap_t *node1, heap_t *node2)
{
	int temp;

	temp = node1->n;
	node1->n = node2->n;
	node2->n = temp;
}

/**
 * heapify_up - Maintains max heap property by moving node up
 * @node: Node to heapify
 */
void heapify_up(heap_t *node)
{
	heap_t *parent;

	if (!node || !node->parent)
		return;

	parent = node->parent;

	if (node->n > parent->n)
	{
		swap_values(node, parent);
		heapify_up(parent);
	}
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the Heap
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *parent;
	int original_value;

	if (!root)
		return (NULL);

	if (!*root)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	parent = find_parent(*root);

	new_node = binary_tree_node(parent, value);
	if (!new_node)
		return (NULL);

	if (!parent->left)
		parent->left = new_node;
	else
		parent->right = new_node;

	original_value = value;
	heapify_up(new_node);

	/* Find the node with the original value */
	if (new_node->n != original_value)
	{
		/* The value was swapped, find where it ended up */
		heap_t *current = new_node;
		while (current && current->n != original_value)
			current = current->parent;
		if (current)
			return (current);
	}

	return (new_node);
}
