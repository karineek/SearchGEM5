// Modification timestamp: 2023-08-14 15:41:40
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr64718.c
static int __attribute__ ((noinline, noclone))
swap (int x)
{
  return (unsigned short) ((unsigned short) x << 8 | (unsigned short) x >> 8);
}

static int a = 0x1234;

int
main (void)
{
  int b = 0x1234;
  if (swap (a) != 0x3412)
    __builtin_abort ();
  if (swap (b) != 0x3412)
    __builtin_abort ();
  return 0;
}
