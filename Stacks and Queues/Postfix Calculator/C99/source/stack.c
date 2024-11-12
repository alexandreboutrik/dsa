#include "stack.h"

#include <err.h>
#include <errno.h>
#include <stdint.h>
#include <stdlib.h>

extern stack *
create(void)
{
  stack *s;

  if ((s = (stack *) malloc(sizeof(stack))) == NULL)
    err(errno, "malloc");

  s->top = -1;

  return s;
}

extern void
push(stack *s, const uint8_t data)
{
  s->data[++s->top] = data;
}

extern uint8_t
pop(stack *s)
{
  return (s->data[s->top--]);
}
