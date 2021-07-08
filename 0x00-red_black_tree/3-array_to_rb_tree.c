#include "rb_trees.h"

/**
 * array_to_rb_tree - builds a Binary Search Tree from an array
 *
 * @array: array
 * @size: size of array
 *
 * Return: tree
 */
rb_tree_t *array_to_rb_tree(int *array, size_t size)
{
	rb_tree_t *tree;
	size_t i;

	if (array == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
		rb_tree_insert(&tree, array[i]);

	return (tree);
}
