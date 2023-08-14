// Modification timestamp: 2023-08-14 13:47:42
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/961122-1.c
long long acc;

addhi (short a)
{
  acc += (long long) a << 32;
}

subhi (short a)
{
  acc -= (long long) a << 32;
}

main ()
{
  acc = 0xffff00000000ll;
  addhi (1);
  if (acc != 0x1000000000000ll)
    abort ();
  subhi (1);
  if (acc != 0xffff00000000ll)
    abort ();
  exit (0);
}
