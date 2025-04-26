#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if the tree is full, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL) /* Check if tree is NULL */
	{
		return (0); /* Tree is not full if NULL */
	}

	if (tree->left == NULL && tree->right == NULL) /* Check if node is a leaf */
	{
		return (1); /* A leaf node is full */
	}

	if (tree->left && tree->right) /* Check if node has both children */
	{
		/* Recursively check if left and right subtrees are full */
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));
	}

	return (0); /* Node is not full if it has only one child */
}
