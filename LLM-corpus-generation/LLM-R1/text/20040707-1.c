// Modification timestamp: 2023-08-14 12:56:29
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20040707-1.c
struct s { char c1, c2; };
void foo (struct s s)
{
  static struct s s1;
  s1 = s;
}
int main ()
{
  static struct s s2;
  foo (s2);
  exit (0);
}
