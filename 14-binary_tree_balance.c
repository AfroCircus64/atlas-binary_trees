#include "binary_trees.h"

/**
 * balanced_tree_height - finds the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: height of the tree, or 0 if tree is NULL
 */
size_t balanced_tree_height(const binary_tree_t *tree)
{
	size_t l = 0; /* Height of the left subtree */
	size_t r = 0; /* Height of the right subtree */

	if (tree == NULL) /* Check if tree is NULL */
	{
		return (0); /* Return 0 if tree is NULL */
	}
	else
	{
		/* Calculate the height of left and right subtrees */
		l = tree->left ? 1 + balanced_tree_height(tree->left) : 1;
		r = tree->right ? 1 + balanced_tree_height(tree->right) : 1;

		/* Return the greater height between left and right subtrees */
		return ((l > r) ? l : r);
	}
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 * Return: balance factor, or 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int right = 0; /* Height of the right subtree */
	int left = 0;  /* Height of the left subtree */
	int total = 0; /* Balance factor */

	if (tree) /* Check if tree is not NULL */
	{
		/* Calculate the height of left and right subtrees */
		left = ((int)balanced_tree_height(tree->left));
		right = ((int)balanced_tree_height(tree->right));

		/* Calculate the balance factor (left height - right height) */
		total = left - right;
	}

	return (total); /* Return the balance factor */
}
