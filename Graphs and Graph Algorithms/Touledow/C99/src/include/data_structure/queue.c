#include "data_structure/queue.h"

#include <err.h>
#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

extern queue *
queue_create(void)
{
    queue *q;

    if ((q = (queue *) malloc(sizeof(queue))) == NULL)
        err(errno, "queue_create: malloc");

    q->head = NULL;
    q->tail = NULL;

    return q;
}

extern uint8_t
queue_empty(queue *q)
{
    return (q->head == NULL) ? 1 : 0;
}

extern void
queue_push(queue *q, const int32_t data)
{
    queue_node *new;

    if ((new = (queue_node *) malloc(sizeof(queue_node))) == NULL)
        err(errno, "queue_push: malloc");

    new->data           = data;
    new->next           = NULL;

    if (queue_empty(q))
    {
        q->head = new;
        q->tail = new;
    }
    else
    {
        q->tail->next = new;
        q->tail       = q->tail->next;
    }
}

extern int32_t
queue_pop(queue *q)
{
    queue_node  *tmp;
    int32_t      ret;

    tmp = q->head->next;
    ret = q->head->data;

    if (q->head != NULL)
        free(q->head);

    q->head = tmp;

    if (q->head == NULL)
        q->tail = NULL;

    return ret;
}

extern void
free_queue(queue *q)
{
    while (! queue_empty(q))
        (void) queue_pop(q);

    if (q != NULL)
        free(q);
}
