#include "rb_trees.h"
/**
 * rb_tree_node - function that creates a Red-Black Tree node
 * @parent: pointer to the parent
 * @value: value
 * @color: color
 * Return: Always 0 (Success)
 */
rb_tree_t *rb_tree_node(rb_tree_t *parent, int value, rb_color_t color)
{
	rb_tree_t *tree;

	tree = malloc(sizeof(rb_tree_t));
	if (!tree)
		return (NULL);

	(*tree).parent = parent;
	(*tree).color = color;
	(*tree).n = value;
	(*tree).left = NULL;
	(*tree).right = NULL;

	return (tree);
}
