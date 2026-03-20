#include <limits.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * avl_helper - Checks if a tree is a valid AVL with BST bounds
 * @tree: pointer to the current node
 * @min: minimum allowed value (exclusive)
 * @max: maximum allowed value (exclusive)
 * @height: pointer to store the height of the subtree
 *
 * Return: 1 if valid AVL, 0 otherwise
 */
static int avl_helper(const binary_tree_t *tree, int min, int max, int *height)
{
	int left_h = 0, right_h = 0;

	if (!tree)
	{
		*height = 0;
		return (1);
	}
	if (tree->n <= min || tree->n >= max)
		return (0);
	if (!avl_helper(tree->left, min, tree->n, &left_h))
		return (0);
	if (!avl_helper(tree->right, tree->n, max, &right_h))
		return (0);
	if (abs(left_h - right_h) > 1)
		return (0);
	*height = 1 + (left_h > right_h ? left_h : right_h);
	return (1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int height = 0;

	if (!tree)
		return (0);
	return (avl_helper(tree, INT_MIN, INT_MAX, &height));
}
