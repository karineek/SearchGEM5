// Modification timestamp: 2023-08-14 16:05:19
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr89826.c
typedef unsigned int u32;
typedef unsigned long long u64;
u64 a;
u32 b;

u64
foo (u32 d)
{
  a -= d ? 0 : ~a;
  return a + b;
}

int
main (void)
{
  u64 x = foo (2);
  if (x != 0)
    __builtin_abort();
  return 0;
}
