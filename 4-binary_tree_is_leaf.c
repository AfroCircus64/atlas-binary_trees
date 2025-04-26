#include "binary_trees.h"

/**
 * binary_tree_is_leaf - checks if a node is a leaf
 * @node: pointer to the node to check
 * Return: 1 if the node is a leaf, otherwise 0
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL) /* Check if node is NULL */
	{
		return (0); /* Not a leaf if node is NULL */
	}

	/* Check if node has no children */
	if (node->left == NULL && node->right == NULL)
	{
		return (1); /* Node is a leaf */
	}

	return (0); /* Node is not a leaf */
}
