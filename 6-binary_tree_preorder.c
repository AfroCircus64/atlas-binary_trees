#include "binary_trees.h"

/**
 * binary_tree_preorder - goes through a binary tree using pre-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL) /* Check if tree or func is NULL */
	{
		return; /* Exit if tree or func is NULL */
	}

	func(tree->n); /* Apply the function to the current node's value */
	binary_tree_preorder(tree->left, func); /* Traverse the left subtree */
	binary_tree_preorder(tree->right, func); /* Traverse the right subtree */
}
