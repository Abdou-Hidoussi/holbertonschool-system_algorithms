#include "graphs.h"

/**
 * link_vert - links specified vertices
 * @save_src: pointer to first vertex
 * @save_dest: pointer to second vertex
 * @type: UNIDIRECTIONAL or BIDIRECTIONAL
 *
 * Return: 1 or 0
 */
int link_vert(vertex_t *save_src, vertex_t *save_dest, edge_type_t type)
{
	edge_t *new, *cur;

	new = malloc(sizeof(*new));
	if (!new)
		return (0);
	new->dest = save_dest;
	new->next = NULL;
	++save_src->nb_edges;
	for (cur = save_src->edges; cur && cur->next; cur = cur->next)
		;
	if (!cur)
		save_src->edges = new;
	else
		cur->next = new;
	if (type == BIDIRECTIONAL)
		return (link_vert(save_dest, save_src, UNIDIRECTIONAL));
	return (1);
}

/**
 * exist - find vertices exist
 * @graph: pointer to graph
 * @src: first vertex
 * @dest: second vertex
 * @save_src: pointer to first vertex
 * @save_dest: pointer to second vertex
 *
 * Return: 1 or 0
 */
int exist(graph_t *graph, const char *src, const char *dest,
		vertex_t **save_src, vertex_t **save_dest)
{
	vertex_t *cur;

	cur = graph->vertices;
	while (cur && (!*save_src || !*save_dest))
	{
		if (!(strcmp(cur->content, src)))
			*save_src = cur;
		if (!(strcmp(cur->content, dest)))
			*save_dest = cur;
		cur = cur->next;
	}
	if (!*save_src || !*save_dest)
		return (0);
	return (1);
}

/**
 * graph_add_edge - add an edge
 * @graph: pointer to graph
 * @src: first vertex
 * @dest: second vertex
 * @type: UNIDIRECTIONAL or BIDIRECTIONAL
 *
 * Return: 1 or 0
 */
int graph_add_edge(graph_t *graph, const char *src, const char *dest,
		edge_type_t type)
{
	vertex_t *save_src, *save_dest;

	if (!graph || !src || !dest ||
			(type != UNIDIRECTIONAL && type != BIDIRECTIONAL))
		return (0);
	save_src = NULL;
	save_dest = NULL;
	if (!exist(graph, src, dest, &save_src, &save_dest))
		return (0);
	return (link_vert(save_src, save_dest, type));
}
