#ifndef _QUEUE_H_TOULEDOW
#define _QUEUE_H_TOULEDOW

#include <stdint.h>

typedef struct queue_node queue_node;
struct queue_node
{
    int32_t      data;
    queue_node  *next;
};

typedef struct queue queue;
struct queue
{
    queue_node  *head;
    queue_node  *tail;
};

extern  queue       *queue_create   (void);
extern  uint8_t      queue_empty    (queue *);
extern  void         free_queue     (queue *);

extern  void         queue_push     (queue *, const int32_t);
extern  int32_t      queue_pop      (queue *);

#endif /* _QUEUE_H_TOULEDOW */
