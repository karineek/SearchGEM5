// Modification timestamp: 2023-08-14 15:08:50
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr42154.c
struct A { char x[1]; };
extern void abort (void);
void __attribute__((noinline,noclone))
foo (struct A a)
{
  if (a.x[0] != 'a')
    abort ();
}
int main ()
{
  struct A a;
  int i;
  for (i = 0; i < 1; ++i)
    a.x[i] = 'a';
  foo (a);
  return 0;
}
