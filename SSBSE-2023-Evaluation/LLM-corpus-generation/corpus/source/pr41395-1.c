// Modification timestamp: 2023-08-14 15:07:30
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr41395-1.c

#include <stdio.h>
#include <stdlib.h>

struct VEC_char_base
{
  unsigned num;
  unsigned alloc;
  short vec[1];
};

short __attribute__((noinline))
foo (struct VEC_char_base *p, int i)
{
  short *q;
  p->vec[i] = 0;
  q = &p->vec[8];
  *q = 1;
  return p->vec[i];
}

extern void abort (void);
extern void *malloc (__SIZE_TYPE__);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int i = atoi(argv[1]);
  struct VEC_char_base *p = malloc (sizeof (struct VEC_char_base) + 256);
  if (foo (p, i) != 1)
    abort ();
  return 0;
}
