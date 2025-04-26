#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 * @parent: parent of the specified node
 * @value: value of the node
 * Return: pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
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

	/* If parent already has a left child, update its parent */
	if (parent->left != NULL)
	{
		new_node->left = parent->left;       /* Link new node to current left child */
		parent->left->parent = new_node;    /* Update parent of current left child */
	}

	/* Set the new node as the left child of the parent */
	parent->left = new_node;

	return (new_node); /* Return the newly created node */
}
