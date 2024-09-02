// Modification timestamp: 2023-08-14 13:52:43
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/990130-1.c
int count = 0;
int dummy;

static int *
bar(void)
{
  ++count;
  return &dummy;
}

static void
foo(void)
{
  asm("" : "+r"(*bar()));
}

main()
{
  foo();
  if (count != 1)
    abort();
  exit(0);
}
