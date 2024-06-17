#include "data_structure/graph.h"

#include <err.h>
#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

extern graph *
init_graph(const uint8_t num_islands)
{
    graph *g;

    if ((g = (graph *) malloc(sizeof(graph))) == NULL)
        err(errno, "init_graph: g malloc");

    if ((g->adjacency_list = (graph_node **) malloc(num_islands * sizeof(graph_node))) == NULL)
        err(errno, "init_graph: adjacency_list malloc");

    for (register uint8_t i = 0; i < num_islands; i++)
        g->adjacency_list[i] = NULL;

    g->sea_level = 0;

    return g;
}

static void
free_list(graph_node *adjacency_list)
{
    if (adjacency_list == NULL)
        return;

    free_list(adjacency_list->next);

    free(adjacency_list);
}

extern void
free_graph(graph *g)
{
    for (register uint32_t i = 0; i < g->num_islands; i++)
        if (g->adjacency_list[i] != NULL)
            free_list(g->adjacency_list[i]);

    if (g->adjacency_list != NULL)
        free(g->adjacency_list);

    if (g != NULL)
        free(g);
}

extern graph_node *
graph_insert(graph_node *adjacency_list, const uint32_t dst_island, const uint32_t bridge_height)
{
    graph_node *new;

    if ((new = (graph_node *) malloc(sizeof(graph_node))) == NULL)
        err(errno, "graph_insert: malloc");

    new->island         = dst_island;
    new->bridge_height  = bridge_height;
    new->next           = adjacency_list;

    return new;
}

