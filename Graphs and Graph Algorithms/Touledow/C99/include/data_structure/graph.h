#ifndef _GRAPH_H_TOULEDOW
#define _GRAPH_H_TOULEDOW

#include <stdint.h>

typedef struct graph_node graph_node;
struct graph_node
{
    uint32_t     island;
    uint32_t     bridge_height;

    graph_node  *next;
};

typedef struct graph graph;
struct graph
{
    uint8_t     src_island, dst_island;

    uint8_t     num_islands;
    uint32_t    num_bridges;

    uint64_t    bridge_height, sea_level;

    /*
     * graph is a list of nodes.
     * each node holds the dst_island and bridge_height data.
     */
    graph_node **adjacency_list;
};

extern  graph       *init_graph    (const uint8_t num_islands);
extern  void         free_graph    (graph *);

extern  graph_node  *graph_insert  (graph_node *, const uint32_t, const uint32_t);

#endif /* _GRAPH_H_TOULEDOW */
