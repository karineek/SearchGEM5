// Modification timestamp: 2023-08-14 15:15:29
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr47299.c
/* PR rtl-optimization/47299 */

extern void abort (void);

__attribute__ ((noinline, noclone)) unsigned short
foo (unsigned char x)
{
  return x * 255;
}

int
main ()
{
  if (foo (0x40) != 0x3fc0)
    abort ();
  return 0;
}
