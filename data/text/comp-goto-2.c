// Modification timestamp: 2023-08-14 14:17:17
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/comp-goto-2.c
/* { dg-require-effective-target label_values } */
/* { dg-require-effective-target trampolines } */
/* { dg-add-options stack_size } */

/* A slight variation of 920501-7.c.  */

#ifdef STACK_SIZE
#define DEPTH ((STACK_SIZE) / 512 + 1)
#else
#define DEPTH 1000
#endif

x(a)
{
  __label__ xlab;
  void y(a)
    {
      void *x = &&llab;
      if (a==-1)
	goto *x;
      if (a==0)
	goto xlab;
    llab:
      y (a-1);
    }
  y (a);
 xlab:;
  return a;
}

main ()
{

  if (x (DEPTH) != DEPTH)
    abort ();

  exit (0);
}
