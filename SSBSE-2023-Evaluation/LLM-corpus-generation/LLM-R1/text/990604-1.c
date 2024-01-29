// Modification timestamp: 2023-08-14 13:55:45
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/990604-1.c
int b;
void f ()
{
  int i = 0;
  if (b == 0)
    do {
      b = i;
      i++;
    } while (i < 10);
}

int main ()
{
  f ();
  if (b != 9)
    abort ();
  return 0;
}
