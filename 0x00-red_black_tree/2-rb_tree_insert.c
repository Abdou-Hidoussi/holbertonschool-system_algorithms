#include "rb_trees.h"
rb_tree_t *fix_right(rb_tree_t *old, int value, rb_color_t  color)
{
	old->parent->left = rb_tree_node(old->parent, value, color);
	old->parent->left->n = old->parent->n;
	old->parent->n = old->n;
	old->n = value;
	return (old);
}
rb_tree_t *fix_left(rb_tree_t *old, int value, rb_color_t  color)
{
	old->parent->right = rb_tree_node(old->parent, value, color);
	old->parent->right->n = old->parent->n;
	old->parent->n = old->n;
	old->n = value;
	return (old);
}
rb_tree_t *rb_tree_insert(rb_tree_t **tree, int value)
{
	rb_tree_t *old = *tree;
	rb_color_t color;

	if (*tree == NULL)
		return (*tree = rb_tree_node(NULL, value, BLACK));
	if (old->color == RED)
		color = BLACK;
	else
		color = RED;
	if (old->n == value)
		return (NULL);

	if (old->n > value)
	{
		if (old->left == NULL)
		{
			if (old->parent)
				if (old->parent->n > value && !old->parent->right
				&& !old->left && !old->right)
					return (fix_left(old, value, color));
			return (old->left = rb_tree_node(old, value, color));
		}
		else
			return (rb_tree_insert(&old->left, value));
	}
	else
	{
		if (old->right == NULL)
		{
			if (old->parent)
				if (old->parent->n < value && !old->parent->left
				&& !old->left && !old->right)
					return (fix_right(old, value, color));
			return (old->right = rb_tree_node(old, value, color));
		}
		else
			return (rb_tree_insert(&old->right, value));
	}
}