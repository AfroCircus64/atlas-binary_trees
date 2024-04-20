#include "binary_trees.h"

/**
 * balanced_tree_height - finds the height of a binary tree
 * @tree: tree
 * Return: height
 */
size_t balanced_tree_height(const binary_tree_t *tree)
{
	size_t l = 0;
	size_t r = 0;

	if (tree == NULL)
	{
		return (0);
	}

	else
	{
		if (tree)
		{
			l = tree->left ? 1 + balanced_tree_height(tree->left) : 1;
			r = tree->right ? 1 + balanced_tree_height(tree->right) : 1;
		}
		return ((l > r) ? l : r);
	}
}

/**
 * binary_tree_balance - Measures balance factor of a binary tree
 * @tree: tree
 * Return: balance
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int right = 0, left = 0, total = 0;

	if (tree)
	{
		left = ((int)balanced_tree_height(tree->left));
		right = ((int)balanced_tree_height(tree->right));
		total = left - right;
	}
	return (total);
}
