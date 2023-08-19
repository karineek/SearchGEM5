// Modification timestamp: 2023-08-14 14:19:14
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/compndlit-1.c
/* The bit-field below would have a problem if __INT_MAX__ is too
   small.  */
#if __INT_MAX__ < 2147483647
int
main (void)
{
  exit (0);
}
#else
struct S
{
  int a:3;
  unsigned b:1, c:28;
};

struct S x = {1, 1, 1};

main ()
{
  x = (struct S) {b:0, a:0, c:({ struct S o = x; o.a == 1 ? 10 : 20;})};
  if (x.c != 10)
    abort ();
  exit (0);
}
#endif
