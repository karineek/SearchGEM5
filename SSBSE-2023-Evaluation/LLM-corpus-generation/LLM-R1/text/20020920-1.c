// Modification timestamp: 2023-08-14 12:36:37
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20020920-1.c
extern void abort (void);
extern void exit (int);

struct B
{
  int x;
  int y;
};

struct A
{
  int z;
  struct B b;
};

struct A
f ()
{
  struct B b = { 0, 1 };
  struct A a = { 2, b };
  return a;
}

int
main (void)
{
  struct A a = f ();
  if (a.z != 2 || a.b.x != 0 || a.b.y != 1)
    abort ();
  exit (0);
}
