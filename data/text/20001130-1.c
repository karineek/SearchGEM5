// Modification timestamp: 2023-08-14 11:54:35
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20001130-1.c
static inline int bar(void) { return 1; }
static int mem[3];

static int foo(int x)
{
  if (x != 0)
    return x;

  mem[x++] = foo(bar());

  if (x != 1)
    abort();

  return 0;
}

int main()
{
  foo(0);
  return 0;
}
