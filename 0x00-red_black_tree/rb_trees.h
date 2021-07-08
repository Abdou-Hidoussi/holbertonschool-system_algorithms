#ifndef TREE_H
#define TREE_H


#include <stdlib.h>
#include <stdio.h>


/**
 * enum rb_color_e - Possible color of a Red-Black tree
 *
 * @RED: 0 -> Red node
 * @BLACK: 1 -> Black node
 * @DOUBLE_BLACK: s
 */
typedef enum rb_color_e
{
	RED = 0,
	BLACK,
	DOUBLE_BLACK
} rb_color_t;

/**
 * struct rb_tree_s - Red-Black tree node structure
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 * @color: Color of the node (RED or BLACK)
 */
typedef struct rb_tree_s
{
	int n;
	rb_color_t color;
	struct rb_tree_s *parent;
	struct rb_tree_s *left;
	struct rb_tree_s *right;
} rb_tree_t;



rb_tree_t *rb_tree_node(rb_tree_t *parent, int value, rb_color_t color);
int rb_tree_is_valid(const rb_tree_t *tree);
int check_tree(const rb_tree_t *tree);

rb_tree_t *fix_right(rb_tree_t *old, int value, rb_color_t  color);
rb_tree_t *fix_left(rb_tree_t *old, int value, rb_color_t  color);
rb_tree_t *rb_tree_insert(rb_tree_t **tree, int value);
rb_tree_t *array_to_rb_tree(int *array, size_t size);

#endif /* TREE_H */
