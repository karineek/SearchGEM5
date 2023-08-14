// Modification timestamp: 2023-08-14 15:09:07
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr42269-2.c
/* Make sure that language + abi extensions in passing S interoperate.  */

static long long __attribute__((noinline))
foo (unsigned short s)
{
  return (short) s;
}

unsigned short s = 0xFFFF;

int
main (void)
{
  return foo (s) + 1 != 0;
}
