#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 * Return: size of the tree, or 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	/* Initialize size, left, and right subtree sizes */
	size_t size = 0, r = 0, l = 0;

	if (tree == NULL) /* Check if tree is NULL */
	{
		return (0); /* Return 0 if tree is NULL */
	}

	else
	{
		/* Recursively calculate size of left and right subtrees */
		l = binary_tree_size(tree->left);
		r = binary_tree_size(tree->right);

		/* Calculate total size (left + right + current node) */
		size = r + l + 1;
	}

	return (size); /* Return the total size of the tree */
}
