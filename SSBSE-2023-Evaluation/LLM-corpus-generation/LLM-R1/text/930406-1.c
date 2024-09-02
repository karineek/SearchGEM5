// Modification timestamp: 2023-08-14 13:33:03
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/930406-1.c
/* { dg-add-options stack_size } */

f()
{
  int x = 1;
#if defined(STACK_SIZE)
  char big[STACK_SIZE/2];
#else
  char big[0x1000];
#endif

  ({
    __label__ mylabel;
  mylabel:
    x++;
    if (x != 3)
      goto mylabel;
  });
  exit(0);
}

main()
{
  f();
}
