// Modification timestamp: 2023-08-14 12:37:41
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20021113-1.c
/* { dg-require-effective-target alloca } */

/* This program tests a data flow bug that would cause constant propagation
   to propagate constants through function calls.  */

foo (int *p)
{
  *p = 10;
}

main()
{
  int *ptr = alloca (sizeof (int));
  *ptr = 5;
  foo (ptr);
  if (*ptr == 5)
    abort ();
  exit (0);
}
