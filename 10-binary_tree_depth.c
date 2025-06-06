#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: pointer to the node to measure the depth
 * Return: depth of the node, or 0 if tree is NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	/* Recursively calculate depth by moving up to the parent */
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}
