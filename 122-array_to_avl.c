#include "binary_trees.h"

/**
 * array_to_avl - builds an AVL tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of elements in the array
 * Return: pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL; /* Pointer to the root of the AVL tree */
	size_t i; /* Loop counter */

	for (i = 0; i < size; i++) /* Iterate through the array */
		avl_insert(&root, array[i]); /* Insert each element into the AVL tree */

	return (root); /* Return the root of the created AVL tree */
}
