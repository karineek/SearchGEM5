// Modification timestamp: 2023-08-14 16:52:44
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/struct-ini-2.c
struct {
  int a:4;
  int :4;
  int b:4;
  int c:4;
} x = { 2,3,4 };

main ()
{
  if (x.a != 2)
    abort ();
  if (x.b != 3)
    abort ();
  if (x.c != 4)
    abort ();
  exit (0);
}
