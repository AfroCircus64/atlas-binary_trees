#include "binary_trees.h"

/**
 * binary_tree_delete - deletes an entire binary tree
 * @tree: tree to be freed
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL) /* Check if tree is NULL */
	{
		return; /* Exit if tree is NULL */
	}

	/* Recursively delete left and right subtrees */
	binary_tree_delete(tree->left);
	binary_tree_delete(tree->right);

	/* Free the current node */
	free(tree);
}
