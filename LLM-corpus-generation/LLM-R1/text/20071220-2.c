// Modification timestamp: 2023-08-14 13:13:04
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20071220-2.c
/* PR tree-optimization/29484 */
/* { dg-require-effective-target label_values } */

extern void abort (void);

void *__attribute__((noinline))
baz (void **lab)
{
  asm volatile ("" : "+r" (lab));
  return *lab;
}

static inline
int bar (void)
{
  static void *b[] = { &&addr };
  baz (b);
addr:
  return 17;
}

int __attribute__((noinline))
f1 (void)
{
  return bar ();
}

int __attribute__((noinline))
f2 (void)
{
  return bar ();
}

int
main (void)
{
  if (f1 () != 17 || f1 () != 17 || f2 () != 17 || f2 () != 17)
    abort ();
  return 0;
}
