// Modification timestamp: 2023-08-14 13:32:39
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/930106-1.c
/* { dg-add-options stack_size } */

#if defined (STACK_SIZE)
#define DUMMY_SIZE 9
#else
#define DUMMY_SIZE 399999
#endif

double g()
{
  return 1.0;
}

f()
{
  char dummy[DUMMY_SIZE];
  double f1, f2, f3;
  f1 = g();
  f2 = g();
  f3 = g();
  return f1 + f2 + f3;
}

main()
{
  if (f() != 3.0)
    abort();
  exit(0);
}
