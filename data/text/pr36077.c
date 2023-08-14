// Modification timestamp: 2023-08-14 14:58:59
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr36077.c
extern void abort (void);

unsigned int test (unsigned int x)
{
  return x / 0x80000001U / 0x00000002U;
}

int main()
{
  if (test(2) != 0)
    abort ();
  return 0;
}
