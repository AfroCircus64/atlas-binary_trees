#include "binary_trees.h"

/**
 * binary_tree_insert_right - add a node as the right-child of another node
 * if the parent already has a right child, it is moved down one level
 * @parent: parent of the specified node
 * @value: value of the node
 * Return: pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	/* Check if parent is NULL */
	if (parent == NULL)
	{
		return (NULL);
	}

	/* Create a new node */
	new_node = binary_tree_node(parent, value);

	/* Check if node creation failed */
	if (new_node == NULL)
	{
		return (NULL);
	}

	/* If parent already has a right child, update its parent */
	if (parent->right != NULL)
	{
		new_node->right = parent->right;       /* Link new node to current right child */
		parent->right->parent = new_node;     /* Update parent of current right child */
	}

	/* Set the new node as the right child of the parent */
	parent->right = new_node;

	return (new_node); /* Return the newly created node */
}
