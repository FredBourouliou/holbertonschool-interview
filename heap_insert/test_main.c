#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * _binary_tree_delete - Deallocate a binary tree
 * @tree: Pointer to the root of the tree to delete
 */
static void _binary_tree_delete(heap_t *tree)
{
	if (tree)
	{
		_binary_tree_delete(tree->left);
		_binary_tree_delete(tree->right);
		free(tree);
	}
}

/**
 * main - Entry point
 *
 * Return: 0 on success, error code on failure
 */
int main(void)
{
	heap_t *root;
	heap_t *node;
	int values[] = {98, 110, 43, 56, 2, 78, 123, 76, 234};
	int i;

	root = NULL;
	for (i = 0; i < 9; i++)
	{
		node = heap_insert(&root, values[i]);
		if (node)
			printf("Value inserted: %d\n", node->n);
	}

	binary_tree_print(root);
	_binary_tree_delete(root);
	return (0);
}
