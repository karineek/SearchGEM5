// Modification timestamp: 2023-08-14 11:58:51
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20010422-1.c
unsigned int foo(unsigned int x)
{
  if (x < 5)
    x = 4;
  else
    x = 8;
  return x;
}

int main(void)
{
  if (foo (8) != 8)
    abort ();
  exit (0);
}
