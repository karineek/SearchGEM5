// Modification timestamp: 2023-08-14 15:11:55
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr43629.c
int flag;
extern void abort (void);
int main()
{
  int x;
  if (flag)
    x = -1;
  else
    x &= 0xff;
  if (x & ~0xff)
    abort ();
  return 0;
}
