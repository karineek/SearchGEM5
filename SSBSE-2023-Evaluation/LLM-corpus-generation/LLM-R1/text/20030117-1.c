// Modification timestamp: 2023-08-14 12:42:05
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20030117-1.c
int foo (int, int, int);
int bar (int, int, int);

int main (void)
{
  if (foo (5, 10, 21) != 12)
    abort ();

  if (bar (9, 12, 15) != 150)
    abort ();

  exit (0);
}

int foo (int x, int y, int z)
{
  return (x + y + z) / 3;
}

int bar (int x, int y, int z)
{
  return foo (x * x, y * y, z * z);
}
