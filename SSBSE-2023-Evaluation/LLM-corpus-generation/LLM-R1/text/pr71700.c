// Modification timestamp: 2023-08-14 15:51:37
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr71700.c
struct S
{
  signed f0 : 16;
  unsigned f1 : 1;
};

int b;
static struct S c[] = {{-1, 0}, {-1, 0}};
struct S d;

int
main ()
{
  struct S e = c[0];
  d = e;
  if (d.f1 != 0)
    __builtin_abort ();
  return 0;
}
