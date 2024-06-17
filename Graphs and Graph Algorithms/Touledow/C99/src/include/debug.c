#include "debug.h"

#include "data_structure/queue.h"
#include "data_structure/graph.h"

#include <inttypes.h>
#include <stdio.h>
#include <stdint.h>

extern void
debug_list_print_all(const uint8_t island, graph *g)
{
    graph_node *tmp = g->adjacency_list[island];

    printf("LIST %" PRIu8 ": ", island);

    while (tmp != NULL)
    {
        printf("[%" PRIu8 ", %" PRIu32 "] -> ", 
               tmp->island, tmp->bridge_height);

        tmp = tmp->next;
    }

    printf(" //\n");
}

extern void
debug_queue_print(queue *q)
{
    queue_node *tmp = q->head;

    printf("QUEUE ");

    while (tmp != NULL)
    {
        printf("%" PRIu8 " -> ", tmp->data);

        tmp = tmp->next;
    }

    printf(" //\n");
}
