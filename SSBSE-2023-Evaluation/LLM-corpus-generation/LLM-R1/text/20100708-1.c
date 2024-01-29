// Modification timestamp: 2023-08-14 13:18:29
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20100708-1.c
/* PR middle-end/44843 */
/* Verify that we don't use the alignment of struct S for inner accesses.  */

struct S
{
  double for_alignment;
  struct { int x, y, z; } a[16];
};

void f(struct S *s) __attribute__((noinline));

void f(struct S *s)
{
  unsigned int i;

  for (i = 0; i < 16; ++i)
    {
      s->a[i].x = 0;
      s->a[i].y = 0;
      s->a[i].z = 0;
    }
}

int main (void)
{
  struct S s;
  f (&s);
  return 0;
}
