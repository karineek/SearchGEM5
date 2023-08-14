// Modification timestamp: 2023-08-14 15:30:39
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr58387.c
extern void abort(void);

int a = -1;

int main ()
{
  int b = a == 0 ? 0 : -a;
  if (b < 1)
    abort ();
  return 0;
}
