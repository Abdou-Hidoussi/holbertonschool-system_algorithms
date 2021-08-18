#include "graphs.h"

/**
 * graph_create - allocates memory to store a graph_t structure
 *
 * Return: pointer to a graph
 */
graph_t *graph_create(void)
{
	graph_t *new = malloc(sizeof(*new));

	if (new)
	{
		new->nb_vertices = 0;
		new->vertices = NULL;
	}
	return (new);
}
