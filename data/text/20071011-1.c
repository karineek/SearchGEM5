// Modification timestamp: 2023-08-14 13:10:14
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20071011-1.c
extern void abort(void);
void foo(int *p)
{
  int x;
  int y;
  x = *p;
  *p = 0;
  y = *p;
  if (x != y)
    return;
  abort ();
}

int main()
{
  int a = 1;
  foo(&a);
  return 0;
}
