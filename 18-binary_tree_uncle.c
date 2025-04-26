#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: pointer to the node to find the uncle
 * Return: pointer to the uncle node, or NULL if no uncle exists
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node || !node->parent || !node->parent->parent) /* Check if node, parent, or grandparent is NULL */
	{
		return (NULL); /* Return NULL if no uncle exists */
	}

	/* Check if the parent is the left child of the grandparent */
	if (node->parent->parent->left == node->parent)
	{
		return (node->parent->parent->right); /* Return the right child (uncle) */
	}

	/* Otherwise, return the left child (uncle) */
	return (node->parent->parent->left);
}
