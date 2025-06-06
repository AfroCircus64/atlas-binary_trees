#include "binary_trees.h"

/**
 * binary_tree_postorder - goes through a binary tree with post-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL) /* Check if tree or func is NULL */
	{
		return; /* Exit if tree or func is NULL */
	}

	/* Traverse the left subtree */
	binary_tree_postorder(tree->left, func);

	/* Traverse the right subtree */
	binary_tree_postorder(tree->right, func);

	/* Apply the function to the current node's value */
	func(tree->n);
}
