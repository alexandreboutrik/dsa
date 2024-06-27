#include "data_structure/search.h"
#include "data_structure/queue.h"

#include <err.h>
#include <errno.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void
depth_first_search(graph *g, uint8_t v,
                   uint8_t *vertex, uint8_t *n_isl, uint32_t *n_brd)
{
    vertex[v] = 1;

    (*n_isl)++;

    /* for each of the v neighbors */
    for (graph_node *nbr = g->adjacency_list[v]; nbr != NULL; nbr = nbr->next)
    {
        if (nbr->bridge_height > g->sea_level)
        {
            (*n_brd)++;

            if (vertex[nbr->island] == 0)
            {
                printf(" %" PRIu8, nbr->island+1);
                depth_first_search(g, nbr->island, vertex, n_isl, n_brd);
            }
        }
    }
}

extern void
archplg(graph *g)
{
    graph_node  *nbr;
    uint8_t     *vertex;
    uint32_t     n_brd;
    uint8_t      n_archplg, n_isl;

    register uint8_t v;

    n_archplg = 0;

    if ((vertex = (uint8_t *) calloc(g->num_islands, sizeof(uint8_t))) == NULL)
        err(errno, "dfs: malloc");

    /* for each of the vertex */
    for (v = 0; v < g->num_islands; v++)
    {
        n_isl = 0;
        n_brd = 0;

        if (vertex[v] == 0)
        {
            printf("[ %" PRIu8, v+1);

            depth_first_search(g, v, vertex, &n_isl, &n_brd);

            printf(" ] (%" PRIu8 " ilhas, %" PRIu8 " pontes)\n", n_isl, n_brd >> 1);

            n_archplg++;
        }
    }

    printf("Total: %" PRIu8 " arquipelagos\n", n_archplg);

    free(vertex);
}

static void
print_path_recursive(uint8_t dst_index, int8_t *parent, uint32_t *n_brd)
{
    if (parent[dst_index] == -1)
    {
        printf("%" PRIu8, dst_index+1);
        return;
    }

    print_path_recursive(parent[dst_index], parent, n_brd);
    printf(" -> %" PRIu8, dst_index+1);

    (*n_brd)++;
}

static uint8_t
breath_first_search(graph *g)
{
    queue   *q;

    uint32_t n_brd = 0;

    uint8_t *distance;
    uint8_t *in_queue;
    int8_t  *parent;

    q = queue_create();

    if ((distance = (uint8_t *) calloc(g->num_islands, sizeof(uint8_t))) == NULL)
        err(errno, "bfs: malloc distance");

    if ((in_queue = (uint8_t *) calloc(g->num_islands, sizeof(uint8_t))) == NULL)
        err(errno, "bfs: malloc in_queue");

    if ((parent = (int8_t *) malloc(g->num_islands * sizeof(int8_t))) == NULL)
        err(errno, "bfs: malloc parent");

    for (uint8_t i = 0; i < g->num_islands; i++)
        parent[i] = -1;

    queue_push(q, g->src_island-1);
    in_queue[g->src_island-1] = 1;

    while (queue_empty(q) == 0)
    {
        #if DEBUG_TOULEDOW
        #include "debug.h"

            debug_queue_print(q);

        #endif

        uint8_t v = queue_pop(q);

        for (graph_node *nbr = g->adjacency_list[v]; nbr != NULL; nbr = nbr->next)
        {
            if (nbr->bridge_height > g->sea_level)
            {
                if (in_queue[nbr->island] == 0)
                {
                    queue_push(q, nbr->island);

                    in_queue[nbr->island] = 1;
                    distance[nbr->island] = distance[v] + 1;
                    parent  [nbr->island] = v;
                }
            }
        }
    }

    if (distance[g->dst_island-1] == 0)
        printf("sem caminho entre %" PRIu8 " e %" PRIu8 "\n",
               g->src_island, g->dst_island);

    else
    {
        print_path_recursive(g->dst_island-1, parent, &n_brd);
        printf(" (%" PRIu8 " pontes)\n", n_brd);
    }

    #if DEBUG_TOULEDOW

    for (uint8_t x = 0; x < g->num_islands; x++)
        printf(" %" PRIi8, parent[x]);
    printf("\n");

    #endif

    free(in_queue);
    free(distance);
    free(parent);

    free_queue(q);

    return 0;
}

extern void
print_path(graph *g)
{
    breath_first_search(g);
}
