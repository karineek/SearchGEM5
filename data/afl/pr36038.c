// Modification timestamp: 2023-08-14 14:58:56
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr36038.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long list[10];
long long expect[10] = { 0, 1, 2, 3, 4, 4, 5, 6, 7, 9 };
long long *stack_base;
int indices[10];
int *markstack_ptr;

void doit(int diff, int shift)
{
  long long *src;
  long long *dst;
  long long *sp = stack_base + 5;
  int count;

  shift = diff - (markstack_ptr[-1] - markstack_ptr[-2]);
  count = (sp - stack_base) - markstack_ptr[-1] + 2;
  src = sp;
  dst = (sp += shift);
  while (--count)
    *dst-- = *src--;
}

int main(int argc, char *argv[])
{
  if (argc != 3) {
    printf("Usage: %s <diff> <shift>\n", argv[0]);
    return 1;
  }

  int diff = atoi(argv[1]);
  int shift = atoi(argv[2]);

  int i;
  for (i = 0; i < 10; i++)
    list[i] = i;

  markstack_ptr = indices + 9;
  markstack_ptr[-1] = 2;
  markstack_ptr[-2] = 1;

  stack_base = list + 2;
  doit(diff, shift);
  if (memcmp(expect, list, sizeof(list)))
    abort();
  return 0;
}
