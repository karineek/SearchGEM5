// Modification timestamp: 2023-08-14 15:27:49
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr57144.c
extern void abort (void);
extern void exit (int);

void __attribute__ ((noinline))
foo(int a)
{
  int z = a > 0 ? a : -a;
  long long x = z;
  if (x > 0x100000000LL)
    abort ();
  else
    exit (0);
}

int
main()
{
  foo (1);
}
