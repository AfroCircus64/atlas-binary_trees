#include "binary_trees.h"

/**
 * avl_insert - inserts a value in an AVL Tree
 * @tree: double pointer to the root node of the AVL tree for inserting the value
 * @value: value to store in the node to be inserted
 * Return: pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node = NULL; /* Pointer to the newly created node */

	if (!tree) /* Check if tree is NULL */
		return (NULL);

	if (!*tree) /* If tree is empty, create the root node */
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	/* Insert in the left subtree if value is less than current node */
	if (value < (*tree)->n)
	{
		if ((*tree)->left) /* Recursively insert in the left subtree */
			new_node = avl_insert(&((*tree)->left), value);
		else /* Create a new node as the left child */
		{
			new_node = binary_tree_node(*tree, value);
			(*tree)->left = new_node;
		}
	}
	/* Insert in the right subtree if value is greater than current node */
	else if (value > (*tree)->n)
	{
		if ((*tree)->right) /* Recursively insert in the right subtree */
			new_node = avl_insert(&((*tree)->right), value);
		else /* Create a new node as the right child */
		{
			new_node = binary_tree_node(*tree, value);
			(*tree)->right = new_node;
		}
	}
	else /* If value already exists, return NULL */
		return (NULL);

	if (!new_node) /* Check if node creation failed */
		return (NULL);

	/* Balance the tree if the left subtree is unbalanced */
	if (binary_tree_balance(*tree) > 1)
	{
		if (value < (*tree)->left->n) /* Perform right rotation */
			*tree = binary_tree_rotate_right(*tree);
		else /* Perform left-right rotation */
		{
			(*tree)->left = binary_tree_rotate_left((*tree)->left);
			*tree = binary_tree_rotate_right(*tree);
		}
	}

	/* Balance the tree if the right subtree is unbalanced */
	if (binary_tree_balance(*tree) < -1)
	{
		if (value > (*tree)->right->n) /* Perform left rotation */
			*tree = binary_tree_rotate_left(*tree);
		else /* Perform right-left rotation */
		{
			(*tree)->right = binary_tree_rotate_right((*tree)->right);
			*tree = binary_tree_rotate_left(*tree);
		}
	}

	return (new_node); /* Return the newly created node */
}
