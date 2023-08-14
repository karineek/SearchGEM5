// Modification timestamp: 2023-08-14 14:43:28
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr17078-1.c
extern void abort(void);

void test(int *ptr)
{
  int i = 1;
  goto useless;
  if (0)
    {
      useless:
      i = 0;
    }
  else
    i = 1;
  *ptr = i;
}

int main()
{
  int i = 1;
  test(&i);
  if (i)
    abort ();
  return 0;
}
