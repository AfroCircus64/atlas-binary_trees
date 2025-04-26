#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: pointer to the root node of the tree to count the leaves
 * Return: number of leaves, or 0 if tree is NULL
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves = 0; /* Initialize the count of leaves */

	if (tree) /* Check if tree is not NULL */
	{
		/* Increment leaves if the node is a leaf (no children) */
		leaves += (!tree->left && !tree->right) ? 1 : 0;

		/* Recursively count leaves in the left and right subtrees */
		leaves += binary_tree_leaves(tree->left);
		leaves += binary_tree_leaves(tree->right);
	}

	return (leaves); /* Return the total number of leaves */
}
