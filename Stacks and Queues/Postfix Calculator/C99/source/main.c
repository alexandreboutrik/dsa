/*
 * Written by Alexandre Boutrik
 *
 * Data Structure & Algorithms I at UTFPR-TD
 * Exercice III
 */

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#include "stack.h"

int
main(void)
{
  stack   *s = create();
  wchar_t  exp[MAX];
  size_t   exp_size, i;

  (void)! scanf("%128ls", &(exp[0]));
  exp_size = wcslen(exp);

  for (i = 0; i < exp_size; i++)
  {
    switch (exp[i])
    {
      case '*':
        push(s, pop(s) * pop(s));
        break;

      case '+':
        push(s, pop(s) + pop(s));
        break;

      default:
        push(s, exp[i] - '0');
    }
  }

  printf("%" PRIu8 "\n", pop(s));

  free(s);

  return 0;
}
