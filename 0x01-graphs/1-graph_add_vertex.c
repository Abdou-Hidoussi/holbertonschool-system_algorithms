#include "graphs.h"
#include <string.h>
/**
 * init - initialisevortex
 * @graph: graph to update
 * @str: string to store in new vertex
 * @cur: last vertex
 * @new: newly made vertex
 * Return: pointer to newly made vertex or NULL
 */
vertex_t *init(graph_t *graph, const char *str, vertex_t *cur, vertex_t *new)
{
	++graph->nb_vertices;
	if (!cur)
	{
		graph->vertices = new;
		new->index = 0;
	}
	else
	{
		cur->next = new;
		new->index = cur->index + 1;
	}
	new->content = strdup(str);
	if (!new->content)
	{
		free(new);
		return (NULL);
	}
	new->nb_edges = 0;
	new->edges = NULL;
	new->next = NULL;
	return (new);
}
/**
 * graph_add_vertex - adds a vertex to an existing graph
 * @graph: the graph
 * @str: the place to add
 * Return: the new vertex
 */
vertex_t *graph_add_vertex(graph_t *graph, const char *str)
{
	vertex_t *new, *cur;

	if (!graph || !str)
		return (NULL);
	for (cur = graph->vertices; cur; cur = cur->next)
	{
		if (!strcmp(cur->content, str))
			return (NULL);
		if (!cur->next)
			break;
	}
	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	else
		return (init(graph, str, cur, new));
}
