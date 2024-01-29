// Modification timestamp: 2023-08-14 15:07:38
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr41395-2.c

#include <stdio.h>
#include <stdlib.h>

struct VEC_char_base
{
  unsigned num;
  unsigned alloc;
  union {
      short vec[1];
      struct {
          int i;
          int j;
          int k;
      } a;
  } u;
};

short __attribute__((noinline))
foo (struct VEC_char_base *p, int i)
{
    short *q;
    p->u.vec[i] = 0;
    q = &p->u.vec[16];
    *q = 1;
    return p->u.vec[i];
}

extern void abort (void);
extern void *malloc (__SIZE_TYPE__);

int main(int argc, char *argv[]) {
    struct VEC_char_base *p = malloc (sizeof (struct VEC_char_base) + 256);
    if (foo (p, atoi(argv[1])) != 1)
        abort ();
    return 0;
}
