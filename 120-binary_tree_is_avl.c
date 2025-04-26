#include "binary_trees.h"
#include "14-binary_tree_balance.c" /* Include balance function for AVL validation */

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int balance; /* Variable to store the balance factor */

	if (!tree) /* Check if tree is NULL */
		return (0); /* Return 0 if tree is NULL */

	/* Validate the left subtree */
	if (tree->left)
	{
		if (tree->left->n >= tree->n) /* Check if left child is greater than or equal to parent */
			return (0); /* Return 0 if invalid */
		if (!binary_tree_is_avl(tree->left)) /* Recursively check left subtree */
			return (0); /* Return 0 if left subtree is not AVL */
	}

	/* Validate the right subtree */
	if (tree->right)
	{
		if (tree->right->n <= tree->n) /* Check if right child is less than or equal to parent */
			return (0); /* Return 0 if invalid */
		if (!binary_tree_is_avl(tree->right)) /* Recursively check right subtree */
			return (0); /* Return 0 if right subtree is not AVL */
	}

	/* Check the balance factor of the current node */
	balance = binary_tree_balance(tree);
	if (balance < -1 || balance > 1) /* AVL trees must have balance factor between -1 and 1 */
		return (0); /* Return 0 if balance factor is invalid */

	return (1); /* Return 1 if tree is a valid AVL Tree */
}
