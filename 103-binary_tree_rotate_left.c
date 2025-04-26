#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 * Return: pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root = NULL; /* Pointer to the new root after rotation */

	if (tree == NULL) /* Check if tree is NULL */
		return (NULL); /* Return NULL if tree is NULL */

	new_root = tree->right; /* Set the right child as the new root */
	if (new_root == NULL) /* Check if right child is NULL */
		return (tree); /* Return the original tree if no right child */

	/* Update the right child of the current root */
	tree->right = new_root->left;
	if (new_root->left != NULL) /* Update parent of the left child if it exists */
		new_root->left->parent = tree;

	/* Perform the rotation */
	new_root->left = tree;
	new_root->parent = tree->parent;
	tree->parent = new_root;

	return (new_root); /* Return the new root */
}
