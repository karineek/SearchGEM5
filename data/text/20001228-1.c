// Modification timestamp: 2023-08-14 11:55:27
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20001228-1.c
int foo1(void)
{
  union {
    char a[sizeof (unsigned)];
    unsigned b;
  } u;

  u.b = 0x01;
  return u.a[0];
}

int foo2(void)
{
  volatile union {
    char a[sizeof (unsigned)];
    unsigned b;
  } u;

  u.b = 0x01;
  return u.a[0];
}

int main(void)
{
  if (foo1() != foo2())
    abort ();
  exit (0);
}
