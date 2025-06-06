#include "binary_trees.h"

/**
 * binary_tree_inorder - goes through a binary tree using in-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL) /* Check if tree or func is NULL */
	{
		return; /* Exit if tree or func is NULL */
	}

	/* Traverse the left subtree */
	binary_tree_inorder(tree->left, func);

	/* Apply the function to the current node's value */
	func(tree->n);

	/* Traverse the right subtree */
	binary_tree_inorder(tree->right, func);
}
