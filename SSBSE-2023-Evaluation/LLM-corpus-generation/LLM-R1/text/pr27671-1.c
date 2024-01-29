// Modification timestamp: 2023-08-14 14:50:42
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr27671-1.c
/* PR rtl-optimization/27671.
   The combiner used to simplify "a ^ b == a" to "a" via
   simplify_relational_operation_1 in simplify-rtx.c.  */

extern void abort (void) __attribute__ ((noreturn));
extern void exit (int) __attribute__ ((noreturn));

static int __attribute__((noinline))
foo (int a, int b)
{
  int c = a ^ b;
  if (c == a)
    abort ();
}

int
main (void)
{
  foo (0, 1);
  exit (0);
}
