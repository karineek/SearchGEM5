// Modification timestamp: 2023-08-14 13:17:52
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20100209-1.c
int bar(int foo)
{
  return (int)(((unsigned long long)(long long)foo) / 8);
}
extern void abort (void);
int main()
{
  if (sizeof (long long) > sizeof (int)
      && bar(-1) != -1)
    abort ();
  return 0;
}
