// Modification timestamp: 2023-08-14 16:52:56
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/struct-ini-4.c
struct s {
  int a[3];
  int c[3];
};

struct s s = {
  c: {1, 2, 3}
};

main()
{
  if (s.c[0] != 1)
    abort ();
  exit (0);
}
