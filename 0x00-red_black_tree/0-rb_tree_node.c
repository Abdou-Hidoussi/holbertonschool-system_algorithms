#include "rb_trees.h"


void rotate_right(rb_tree_t **tree, rb_tree_t *node)
{
	rb_tree_t *leaf = node->left;

	if (!leaf)
		return;

	node->left = leaf->right;

	if (leaf->right)
		leaf->right->parent = node;

	leaf->parent = node->parent;

	if (!node->parent)
		*tree = leaf;
	else if (node == node->parent->right)
		node->parent->right = leaf;
	else
		node->parent->left = leaf;

	leaf->right = node;
	node->parent = leaf;
}


void rotate_left(rb_tree_t **tree, rb_tree_t *node)
{
	rb_tree_t *leaf = node->right;

	if (!leaf)
		return;
	node->right = leaf->left;

	if (leaf->left)
		leaf->left->parent = node;

	leaf->parent = node->parent;

	if (!node->parent)
		*tree = leaf;
	else if (node == node->parent->left)
		node->parent->left = leaf;
	else
		node->parent->right = leaf;

	leaf->left = node;
	node->parent = leaf;
}

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
