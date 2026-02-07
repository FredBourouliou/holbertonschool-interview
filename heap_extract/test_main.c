#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_node - Creates a binary tree node
 * @parent: Pointer to the parent node
 * @value: Value to put in the new node
 *
 * Return: Pointer to the new node, or NULL on failure
 */
heap_t *binary_tree_node(heap_t *parent, int value)
{
	heap_t *new_node;

	new_node = malloc(sizeof(heap_t));
	if (!new_node)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}

/**
 * _binary_tree_delete - Deletes an entire binary tree
 * @tree: Pointer to the root node of the tree
 */
void _binary_tree_delete(binary_tree_t *tree)
{
	if (!tree)
		return;
	_binary_tree_delete(tree->left);
	_binary_tree_delete(tree->right);
	free(tree);
}

/**
 * main - Entry point for testing
 *
 * Return: 0 on success
 */
int main(void)
{
	heap_t *root;
	int extract;

	/*
	 * Create a simple max heap:
	 *          98
	 *        /    \
	 *      95      91
	 *     /  \    /
	 *   84   79  87
	 */
	root = binary_tree_node(NULL, 98);
	root->left = binary_tree_node(root, 95);
	root->right = binary_tree_node(root, 91);
	root->left->left = binary_tree_node(root->left, 84);
	root->left->right = binary_tree_node(root->left, 79);
	root->right->left = binary_tree_node(root->right, 87);

	printf("Initial heap root: %d\n", root->n);

	extract = heap_extract(&root);
	printf("Extracted: %d\n", extract);
	if (root)
		printf("New root: %d\n", root->n);

	extract = heap_extract(&root);
	printf("Extracted: %d\n", extract);
	if (root)
		printf("New root: %d\n", root->n);

	extract = heap_extract(&root);
	printf("Extracted: %d\n", extract);
	if (root)
		printf("New root: %d\n", root->n);

	/* Test extracting until empty */
	while (root)
	{
		extract = heap_extract(&root);
		printf("Extracted: %d\n", extract);
	}

	/* Test on NULL */
	extract = heap_extract(&root);
	printf("Extract from empty: %d\n", extract);

	return (0);
}
