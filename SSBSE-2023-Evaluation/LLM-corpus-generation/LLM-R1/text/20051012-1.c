// Modification timestamp: 2023-08-14 13:05:03
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20051012-1.c
/* { dg-require-effective-target untyped_assembly } */
extern void abort (void);

struct type
{
  int *a;

  int b:16;
  unsigned int p:9;
} t;

unsigned int
foo ()
{
  return t.p;
}

int
main (void)
{
  t.p = 8;
  if (foo (t) != 8)
    abort ();
  return 0;
}
