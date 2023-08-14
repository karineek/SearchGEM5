// Modification timestamp: 2023-08-14 13:45:40
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/960326-1.c
struct s
{
  int a;
  int b;
  short c;
  int d[3];
};

struct s s = { .b = 3, .d = {2,0,0} };

main ()
{
  if (s.b != 3)
    abort ();
  exit (0);
}
