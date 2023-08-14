// Modification timestamp: 2023-08-14 15:03:46
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr39120.c
struct X { int *p; } x;

struct X __attribute__((noinline))
foo(int *p) { struct X x; x.p = p; return x; }

void __attribute((noinline))
bar() { *x.p = 1; }

extern void abort (void);
int main()
{
  int i = 0;
  x = foo(&i);
  bar();
  if (i != 1)
    abort ();
  return 0;
}
