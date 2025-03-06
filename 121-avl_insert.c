#include "binary_trees.h"

/**
 * avl_insert - inserts a value in an AVL Tree
 * @tree: double pointer to the root node of the AVL tree for inserting the value
 * @value: value to store in the node to be inserted
 * Return: pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node = NULL;

	if (!tree)
		return (NULL);

	if (!*tree)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	if (value < (*tree)->n)
	{
		if ((*tree)->left)
			new_node = avl_insert(&((*tree)->left), value);
		else
		{
			new_node = binary_tree_node(*tree, value);
			(*tree)->left = new_node;
		}
	}
	else if (value > (*tree)->n)
	{
		if ((*tree)->right)
			new_node = avl_insert(&((*tree)->right), value);
		else
		{
			new_node = binary_tree_node(*tree, value);
			(*tree)->right = new_node;
		}
	}
	else
		return (NULL);

	if (!new_node)
		return (NULL);

	if (binary_tree_balance(*tree) > 1)
	{
		if (value < (*tree)->left->n)
			*tree = binary_tree_rotate_right(*tree);
		else
		{
			(*tree)->left = binary_tree_rotate_left((*tree)->left);
			*tree = binary_tree_rotate_right(*tree);
		}
	}
	if (binary_tree_balance(*tree) < -1)
	{
		if (value > (*tree)->right->n)
			*tree = binary_tree_rotate_left(*tree);
		else
		{
			(*tree)->right = binary_tree_rotate_right((*tree)->right);
			*tree = binary_tree_rotate_left(*tree);
		}
	}

	return (new_node);
}
