#include "graphs.h"
#include <string.h>
/**
*_strcpy - 0
*@src: src
*@dest: dest
*Return: dest
*/
char *_strcpy(char *dest, char const *src)
{
	int i = 0, j;

	while (src[i] != '\0')
	{
		i++;
	}

	j = 0;
	while (j <= i)
	{
		dest[j] = src[j];
		j++;
	}
	return (dest);
}
/**
 * graph_add_vertex - adds a vertex to an existing graph
 * @graph: the graph
 * @str: the place to add
 * Return: the new vertex
 */
vertex_t *graph_add_vertex(graph_t *graph, const char *str)
{
	vertex_t *new = malloc(sizeof(*new));
	vertex_t *count = malloc(sizeof(*count));
	char *name = malloc(sizeof(*str));

	_strcpy(name, str);
	if (new)
	{
		new->index = graph->nb_vertices;
		new->content = name;
		new->next = NULL;
		graph->nb_vertices++;
	}
	if (graph->vertices == NULL)
	{
		graph->vertices = new;
		free(count);
		return (new);
	}
	count = graph->vertices;
	while (count != NULL)
	{
		if (count->next == NULL)
		{
			count->next = new;
			break;
		}
		count = count->next;
	}
	free(count);
	return (new);
}
