#include "binary_trees.h"

/**
 * binary_tree_is_root - checks if a node is a root
 * @node: Node to check
 * Return: 1 if the node is a root, 0 otherwise
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL || node->parent != NULL) /* Check if node is NULL or has a parent */
	{
		return (0); /* Not a root if node is NULL or has a parent */
	}

	return (1); /* Node is a root */
}
