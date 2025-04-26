#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: height of the tree, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l = 0; /* Height of the left subtree */
	size_t r = 0; /* Height of the right subtree */

	if (tree == NULL) /* Check if tree is NULL */
	{
		return (0); /* Return 0 if tree is NULL */
	}

	/* Calculate the height of left and right subtrees */
	l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	r = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	/* Return the greater height between left and right subtrees */
	return ((l > r) ? l : r);
}
