// Modification timestamp: 2023-08-14 14:54:29
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr33382.c
struct Foo {
  int i;
  int j[];
};

struct Foo x = { 1, { 2, 0, 2, 3 } };

int foo(void)
{
  x.j[0] = 1;
  return x.j[1];
}

extern void abort(void);

int main()
{
  if (foo() != 0)
    abort();
  return 0;
}
