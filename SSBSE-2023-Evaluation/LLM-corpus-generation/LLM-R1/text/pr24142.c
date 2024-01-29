// Modification timestamp: 2023-08-14 14:49:21
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr24142.c
void abort (void);

int f (int a, int b)
{
  if (a == 1)
    a = 0;
  if (b == 0)
    a = 1;
  if (a != 0)
    return 0;
  return 1;
}

int main (void)
{
  if (f (1, 1) != 1)
    abort ();
  return 0;
}
