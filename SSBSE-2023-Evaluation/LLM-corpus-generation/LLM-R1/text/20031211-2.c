// Modification timestamp: 2023-08-14 12:50:47
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20031211-2.c
struct a
{
  unsigned int bitfield : 3;
};

int main()
{
  struct a a;

  a.bitfield = 131;
  foo (a.bitfield);
  exit (0);
}

foo(unsigned int z)
{
  if (z != 3)
    abort ();
}
