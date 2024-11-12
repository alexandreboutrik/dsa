#ifndef _PFC_STACK_H
#define _PFC_STACK_H

#include <stdint.h>

#define   MAX   128

typedef struct stack stack;
struct stack
{
  uint8_t   data[MAX];
  int16_t   top;
};

extern  stack     *create   (void);
extern  void       push     (stack *, const uint8_t);
extern  uint8_t    pop      (stack *);

#endif /* _PFC_STACK_H */
