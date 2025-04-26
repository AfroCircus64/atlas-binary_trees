#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a node
 * @node: pointer to the node to find the sibling
 * Return: pointer to the sibling node, or NULL if no sibling
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent) /* Check if node or parent is NULL */
		return (NULL); /* Return NULL if no sibling exists */

	/* Check if the node is the left child */
	if (node->parent->left == node)
		return (node->parent->right); /* Return the right sibling */

	/* Otherwise, return the left sibling */
	return (node->parent->left);
}
