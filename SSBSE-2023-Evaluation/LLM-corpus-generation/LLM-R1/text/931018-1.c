// Modification timestamp: 2023-08-14 13:39:22
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/931018-1.c
unsigned int a[0x1000];
extern const unsigned long v;

main ()
{
  f (v);
  f (v);
  exit (0);
}

f (a)
     unsigned long a;
{
  if (a != 0xdeadbeefL)
    abort();
}

const unsigned long v = 0xdeadbeefL;
