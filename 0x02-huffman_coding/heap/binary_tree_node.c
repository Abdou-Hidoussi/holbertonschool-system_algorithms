#include "heap.h"
/**
 * binary_tree_node - create binary tree node
 * @parent: pointer to parent
 * @data: data of the node
 * Return: pointer or NULL
 */
binary_tree_node_t *binary_tree_node(binary_tree_node_t *parent, void *data)
{
	binary_tree_node_t *node = malloc(sizeof(*node));

	if (!node)
		return (NULL);
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	node->parent = parent;
	return (node);
}
