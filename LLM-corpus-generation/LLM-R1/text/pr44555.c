// Modification timestamp: 2023-08-14 15:13:05
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr44555.c
struct a {
    char b[100];
};
int foo(struct a *a)
{
  if (&a->b)
    return 1;
  return 0;
}
extern void abort (void);
int main()
{
  if (foo((struct a *)0) != 0)
    abort ();
  return 0;
}
