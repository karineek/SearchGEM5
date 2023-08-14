// Modification timestamp: 2023-08-14 13:10:10
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20070919-1.c
/* PR c/33238 */
/* { dg-require-effective-target alloca } */

typedef __SIZE_TYPE__ size_t;
int memcmp (const void *, const void *, size_t);
void abort (void);

void
__attribute__((noinline))
bar (void *x, void *y)
{
  struct S { char w[8]; } *p = x, *q = y;
  if (memcmp (p->w, "zyxwvut", 8) != 0)
    abort ();
  if (memcmp (q[0].w, "abcdefg", 8) != 0)
    abort ();
  if (memcmp (q[1].w, "ABCDEFG", 8) != 0)
    abort ();
  if (memcmp (q[2].w, "zyxwvut", 8) != 0)
    abort ();
  if (memcmp (q[3].w, "zyxwvut", 8) != 0)
    abort ();
}

void
__attribute__((noinline))
foo (void *x, int y)
{
  struct S { char w[y]; } *p = x, a;
  int i;
  a = ({ struct S b; b = p[2]; p[3] = b; });
  bar (&a, x);
}

int
main (void)
{
  struct S { char w[8]; } p[4]
    = { "abcdefg", "ABCDEFG", "zyxwvut", "ZYXWVUT" };
  foo (p, 8);
  return 0;
}
