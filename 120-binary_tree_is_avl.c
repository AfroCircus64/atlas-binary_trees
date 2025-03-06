#include "binary_trees.h"
#include "14-binary_tree_balance.c"

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int balance;

	if (!tree)
		return (0);

	if (tree->left)
	{
		if (tree->left->n >= tree->n)
			return (0);
		if (!binary_tree_is_avl(tree->left))
			return (0);
	}

	if (tree->right)
	{
		if (tree->right->n <= tree->n)
			return (0);
		if (!binary_tree_is_avl(tree->right))
			return (0);
	}

	balance = binary_tree_balance(tree);
	if (balance < -1 || balance > 1)
		return (0);

	return (1);
}
