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

rb_tree_t *left_unc(rb_tree_t **tree, rb_tree_t *leaf)
{
	rb_tree_t *head, *unc = leaf->parent->parent->left;

	if (unc && unc->color == RED)
	{
		leaf->parent->color = BLACK;
		unc->color = BLACK;
		head = leaf->parent->parent;
		head->color = RED;
		leaf = head;
	}
	else
	{
		if (leaf == leaf->parent->left)
		{
			leaf = leaf->parent;
			rotate_right(tree, leaf);
		}
		leaf->parent->color = BLACK;
		leaf->parent->parent->color = RED;
		rotate_left(tree, leaf->parent->parent);
	}
	return (leaf);
}


rb_tree_t *right_unc(rb_tree_t **tree, rb_tree_t *leaf)
{
	rb_tree_t *head, *unc = leaf->parent->parent->right;

	if (unc && unc->color == RED)
	{
		leaf->parent->color = BLACK;
		leaf->color = BLACK;
		head = leaf->parent->parent;
		head->color = RED;
		leaf = head;
	}
	else
	{
		if (leaf == leaf->parent->right)
		{
			leaf = leaf->parent;
			rotate_left(tree, leaf);
		}
		leaf->parent->color = BLACK;
		leaf->parent->parent->color = RED;
		rotate_right(tree, leaf->parent->parent);
	}
	return (leaf);
}


void recolor(rb_tree_t **tree, rb_tree_t *leaf)
{
    rb_tree_t *t = *tree;

	while (leaf->parent && leaf->parent->color == RED)
	{
		if (leaf->parent->parent &&
			leaf->parent == leaf->parent->parent->left)
			leaf = right_unc(tree, leaf);
		else
			leaf = left_unc(tree, leaf);
	}

	t->color = BLACK;
}


rb_tree_t *add_leaf(rb_tree_t **tree, int value)
{
	rb_tree_t *this = *tree, *old, *new;

	while (this)
	{
		old = this;

		if (value < this->n)
			this = this->left;
		else if (value > this->n)
			this = this->right;
		else
			return (NULL);
	}

	new = rb_tree_node(NULL, value, RED);
	if (!new)
		return (NULL);

	new->parent = old;

	if (!old)
		*tree = new;
	else if (new->n < old->n)
		old->left = new;
	else
		old->right = new;

	return (new);
}


rb_tree_t *rb_tree_insert(rb_tree_t **tree, int value)
{
	rb_tree_t *new;

	if (!tree)
		return (NULL);

	new = add_leaf(tree, value);
	if (new)
		recolor(tree, new);

	return (new);
}