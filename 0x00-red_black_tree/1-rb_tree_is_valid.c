#include "rb_trees.h"
/**
 * check_tree - checks if a binary tree is a valid Red-Black Tree
 * @tree: pointer to the tree
 * Return: 1 if tree is a valid Red-Black Tree, and 0 otherwise
 */
int check_tree(const rb_tree_t *tree)
{

	if (!tree->left && !tree->right)
		return (1);

	if (!tree->color)
		return (0);

	if (tree->color == RED)
	{
		if (tree->parent->color == tree->color)
			return (0);
		if (tree->color == tree->left->color || tree->color == tree->right->color)
			return (0);
	}

	if (tree->left && !tree->right)
		return (0);
	if (!tree->left && tree->right)
		return (0);

	return (check_tree(tree->right) && check_tree(tree->left));
}
/**
 * rb_tree_is_valid - checks if a binary tree is a valid Red-Black Tree
 * @tree: pointer to the tree
 * Return: 1 if tree is a valid Red-Black Tree, and 0 otherwise
 */
int rb_tree_is_valid(const rb_tree_t *tree)
{
	if (!tree)
		return (0);

	if (tree->color != BLACK)
		return (0);

	return (check_tree(tree->right) && check_tree(tree->left));
}
