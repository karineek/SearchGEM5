// Modification timestamp: 2023-08-14 13:21:49
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20140326-1.c
int a;

int
main (void)
{
  char e[2] = { 0, 0 }, f = 0;
  if (a == 131072)
    f = e[a];
  return f;
}
