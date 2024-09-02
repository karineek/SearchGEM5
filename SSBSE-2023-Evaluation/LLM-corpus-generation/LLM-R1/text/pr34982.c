// Modification timestamp: 2023-08-14 14:57:30
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr34982.c
extern void abort (void);

static void something();

int main()
{
  something(-1);
  return 0;
}

static void something(int i)
{
  if (i != -1)
    abort ();
}
