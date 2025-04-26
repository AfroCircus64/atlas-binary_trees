#include "binary_trees.h"
#include "9-binary_tree_height.c" /* Include height function for calculations */

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if perfect, 0 if not
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int left_height, right_height; /* Heights of left and right subtrees */

	if (tree == NULL) /* Check if tree is NULL */
	{
		return (0); /* Tree is not perfect if NULL */
	}

	/* Calculate the height of left and right subtrees */
	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	/* Check if left and right subtree heights are equal */
	if (left_height == right_height)
	{
		return (1); /* Tree is perfect if heights are equal */
	}

	return (0); /* Tree is not perfect if heights differ */
}
