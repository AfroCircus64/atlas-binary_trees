#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
 * @tree: pointer to the root node of the tree to count the nodes
 * Return: number of nodes with at least 1 child, or 0 if tree is NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes = 0; /* Initialize the count of nodes */

	if (tree) /* Check if tree is not NULL */
	{
		/* Increment nodes if the current node has at least 1 child */
		nodes += (tree->left || tree->right) ? 1 : 0;

		/* Recursively count nodes in the left and right subtrees */
		nodes += binary_tree_nodes(tree->left);
		nodes += binary_tree_nodes(tree->right);
	}

	return (nodes); /* Return the total number of nodes with at least 1 child */
}
