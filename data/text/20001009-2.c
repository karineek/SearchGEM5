// Modification timestamp: 2023-08-14 11:52:22
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20001009-2.c
int b=1;
int foo()
{
  int a;
  int c;
  a=0xff;
  for (;b;b--)
  {
    c=1;
    asm(""::"r"(c));
    c=(signed char)a;
  }
  if (c!=-1)
    abort();
  return c;
}
int main()
{
  foo();
  return 0;
}
