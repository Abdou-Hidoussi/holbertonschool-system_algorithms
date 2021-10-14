#include "graphs.h"
/**
 * del_edge - delete all edges
 * @cur:  pointer to first edge
 */
void del_edge(edge_t *cur)
{
	edge_t *tmp;

	if (!cur)
		return;
	while (cur)
	{
		tmp = cur;
		cur = cur->next;
		free(tmp);
	}
}

/**
 * del_vert - delete all vertices
 * @cur: pointer to first vertex
 */
void del_vert(vertex_t *cur)
{
	vertex_t *tmp;

	if (!cur)
		return;
	while (cur)
	{
		tmp = cur;
		free(cur->content);
		del_edge(cur->edges);
		cur = cur->next;
		free(tmp);
	}
}

/**
 * graph_delete - delete a graph
 * @graph: pointer to graph
 */
void graph_delete(graph_t *graph)
{
	if (!graph)
		return;
	del_vert(graph->vertices);
	free(graph);
}
