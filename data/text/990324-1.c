// Modification timestamp: 2023-08-14 13:53:05
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/990324-1.c
void f(long i)
{
  if ((signed char)i < 0 || (signed char)i == 0)
    abort ();
  else
    exit (0);
}

main()
{
  f(0xffffff01);
}
