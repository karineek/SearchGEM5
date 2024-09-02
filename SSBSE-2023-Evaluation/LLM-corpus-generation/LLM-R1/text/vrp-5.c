// Modification timestamp: 2023-08-14 17:04:14
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/vrp-5.c
/* { dg-require-effective-target int32plus } */
extern void exit (int);
extern void abort ();

void test(unsigned int a, unsigned int b)
{
  if (a < 5)
    abort();
  if (b < 5)
    abort();
  if (a + b != 0U)
    abort();
}

int main(int argc, char *argv[])
{
  unsigned int x = 0x80000000;
  test(x, x);
  exit (0);
}
