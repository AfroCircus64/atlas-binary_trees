#include "binary_trees.h"

/**
 * binary_tree_node - Create a binary node
 * @parent: pointer to parent node
 * @value: value of the node
 * Return: new node or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	/* Allocate memory for the new node */
	new_node = malloc(sizeof(binary_tree_t));

	/* Check if memory allocation failed */
	if (new_node == NULL)
	{
		return (NULL);
	}

	/* Initialize the new node's attributes */
	new_node->n = value;       /* Set the value of the node */
	new_node->parent = parent; /* Set the parent of the node */
	new_node->left = NULL;     /* Initialize left child to NULL */
	new_node->right = NULL;    /* Initialize right child to NULL */

	return (new_node); /* Return the newly created node */
}
