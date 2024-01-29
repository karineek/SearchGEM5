// Modification timestamp: 2023-08-14 14:28:43
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/ifcvt-onecmpl-abs-1.c

extern void abort(void);

__attribute__ ((noinline))
int foo(int n)
{
  if (n < 0)
    n = ~n;

  return n;
}

int main(void)
{
  if (foo (-1) != 0)
    abort ();

  return 0;
}
