// Modification timestamp: 2023-08-14 11:59:29
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20010605-1.c
int main ()
{
  int v = 42;

  inline int fff (int x)
    {
      return x*10;
    }

  return (fff (v) != 420);
}
