// Modification timestamp: 2023-08-14 15:22:51
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr52979-2.c
/* PR middle-end/52979 */
/* { dg-require-effective-target int32plus } */

extern void abort (void);
int c, d, e;

void
foo (void)
{
}

struct __attribute__((packed)) S { int g : 31; int h : 6; };
static struct S b = { 1 };
struct S a = { 1 };

void
bar (void)
{
  a.h = 1;
  struct S f = { };
  b = f;
  e = 0;
  if (d)
    c = a.g;
}

void
baz (void)
{
  bar ();
  a = b;
}

int
main ()
{
  baz ();
  if (a.g)
    abort ();
  return 0;
}
