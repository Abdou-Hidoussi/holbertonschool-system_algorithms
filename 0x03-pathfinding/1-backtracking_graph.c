#include"pathfinding.h"

/**
 * calculate - recursivly find the path
 * @queue: queue with points
 * @visited: visited points
 * @pointer: pointer to city
 * @target: target point
 * Return: queue with points or NULL if failed
*/
int calculate(queue_t **queue, int *visited, vertex_t const *pointer,
				vertex_t const *target)
{
	edge_t *edge;
	int ret;

	if (!target || !pointer || !visited || visited[pointer->index])
	{
		return (0);
	}
	printf("Checking %s\n", pointer->content);
	if (!strcmp(pointer->content, target->content))
	{
		queue_push_front(*queue, strdup(pointer->content));
		return (1);
	}
	visited[pointer->index] = 1;
	edge = pointer->edges;
	while (edge)
	{
		ret = calculate(queue, visited, edge->dest, target);
		if (ret)
		{
			queue_push_front(*queue, strdup(pointer->content));
			return (1);
		}
		edge = edge->next;
	}
	visited[pointer->index] = 0;
	return (0);
}

/**
 * backtracking_graph - backtracking function to find
 * a solution to a maze
 * @graph: map or graph
 * @start: start position on the @map
 * @target: target point
 * Return: queue with points or NULL if failed
*/
queue_t *backtracking_graph(graph_t *graph, vertex_t const *start,
				vertex_t const *target)
{
	int *visited = NULL;
	queue_t *que = NULL;
	int s;

	if (!graph || !start || !target)
		return (NULL);
	visited = calloc(graph->nb_vertices, sizeof(*visited));
	if (!visited)
		return (NULL);
	que = queue_create();
	if (!que)
		return (NULL);
	s = calculate(&que, visited, start, target);
	free(visited);
	if (!s)
	{
		queue_delete(que);
		return (NULL);
	}
	return (que);
}
