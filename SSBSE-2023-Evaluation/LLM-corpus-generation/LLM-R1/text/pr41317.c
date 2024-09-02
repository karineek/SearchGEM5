// Modification timestamp: 2023-08-14 15:07:23
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr41317.c
extern void abort (void);

struct A
{
  int i;
};
struct B
{
  struct A a;
  int j;
};

static void
foo (struct B *p)
{
  ((struct A *)p)->i = 1;
}

int main()
{
  struct A a;
  a.i = 0;
  foo ((struct B *)&a);
  if (a.i != 1)
    abort ();
  return 0;
}
