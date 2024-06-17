/*
 ***************************************
 *         Alexandre Boutrik           *
 ***************************************
 *     TOULEDOW    *    Trabalho II    *
 ***************************************
 * Algoritmos e Estruturas de Dados II *
 ***************************************
 */

#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "data_structure/graph.h"
#include "data_structure/search.h"

#if DEBUG_TOULEDOW
#include "debug.h"
#endif

int
main(void)
{
    graph  *g;
    uint8_t num_islands, nl = 0;
    char    input[16];

    /* cannot do &(g->num_islands) here because g is not allocated yet */
    scanf("%" SCNu8, &num_islands);

    g = init_graph(num_islands);

    g->num_islands = num_islands;
    scanf("%" SCNu32, &(g->num_bridges));

    for (register uint32_t i = 0; i < g->num_bridges; i++)

    {
        scanf("%" SCNu8 " %" SCNu8 " %" SCNu64, 
              &(g->src_island), &(g->dst_island), &(g->bridge_height));

        /*
         * insert at [src-1] and [dst-1], the adjacency_list is symmetrical
         */
        g->adjacency_list[g->src_island-1] = graph_insert(g->adjacency_list[g->src_island-1],
                                                          g->dst_island-1, g->bridge_height);

        g->adjacency_list[g->dst_island-1] = graph_insert(g->adjacency_list[g->dst_island-1],
                                                          g->src_island-1, g->bridge_height);

        #if DEBUG_TOULEDOW

        printf(" input: %" PRIu8 " - %" PRIu8 " , bh: %" PRIu64 "\n",
               g->src_island, g->dst_island, g->bridge_height);

        debug_list_print_all(g->src_island-1, g);
        debug_list_print_all(g->dst_island-1, g);

        printf("\n");

        #endif
    }

    #if DEBUG_TOULEDOW
    for (register uint32_t i = 0; i < g->num_islands; i++)
        debug_list_print_all(i, g);
        printf("\n");
    #endif

    while (scanf("%10s", &(input[0])) != 0)
    {
        if (strcmp(input, "fim") == 0)
            break;

        if (nl != 0) printf("\n");

        if (strcmp(input, "agua") == 0)
        {
            scanf("%" SCNu64, &(g->sea_level));

            printf("Nivel da agua: %" PRIu64 " m\n", g->sea_level);
        }

        if (strcmp(input, "arq") == 0)
            archplg(g);

        if (strcmp(input, "caminho") == 0)
        {
            scanf("%" SCNu8 " %" SCNu8, &(g->src_island), &(g->dst_island));

            if (g->src_island == g->dst_island)
                printf("%" PRIu8 " (0 pontes)\n", g->src_island);

            else
                print_path(g);
        }

        if (nl == 0) nl = 1;
    }

    free_graph(g);
    return 0;
}
