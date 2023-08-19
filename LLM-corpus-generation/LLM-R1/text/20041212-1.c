// Modification timestamp: 2023-08-14 13:00:08
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20041212-1.c
/* A function pointer compared with a void pointer should not be canonicalized.
   See PR middle-end/17564.  */
void *f (void) __attribute__ ((__noinline__));
void *
f (void)
{
  return f;
}
int
main (void)
{
  if (f () != f)
    abort ();
  exit (0);
}
