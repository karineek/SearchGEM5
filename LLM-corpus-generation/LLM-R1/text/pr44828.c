// Modification timestamp: 2023-08-14 15:13:25
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr44828.c
extern void abort (void);

static signed char
foo (signed char si1, signed char si2)
{
  return si1 * si2;
}

int a = 0x105F61CA;

int
main (void)
{
  int b = 0x0332F5C8;
  if (foo (b, a) > 0)
    abort ();
  return 0;
}
