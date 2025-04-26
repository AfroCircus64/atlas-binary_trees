#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 * Return: pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root = NULL; /* Pointer to the new root after rotation */

	if (tree == NULL) /* Check if tree is NULL */
		return (NULL); /* Return NULL if tree is NULL */

	new_root = tree->left; /* Set the left child as the new root */
	if (new_root == NULL) /* Check if left child is NULL */
		return (tree); /* Return the original tree if no left child */

	/* Update the left child of the current root */
	tree->left = new_root->right;
	if (new_root->right != NULL) /* Update parent of the right child if it exists */
		new_root->right->parent = tree;

	/* Perform the rotation */
	new_root->right = tree;
	new_root->parent = tree->parent;
	tree->parent = new_root;

	return (new_root); /* Return the new root */
}
