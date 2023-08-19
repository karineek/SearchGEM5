// Modification timestamp: 2023-08-14 15:39:03
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr61306-3.c
short a = -1;
int b;
char c;

int
main ()
{
  c = a;
  b = a | c;
  if (b != -1)
    __builtin_abort ();
  return 0;
}
