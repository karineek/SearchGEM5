// Modification timestamp: 2023-08-14 13:22:29
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20141107-1.c
#define bool _Bool

bool f(int a, bool c) __attribute__((noinline));
bool f(int a, bool c)
{
  if (!a)
    c = !c;
  return c;
}

void checkf(int a, bool b)
{
  bool c = f(a, b);
  char d;
  __builtin_memcpy (&d, &c, 1);
  if ( d != (a==0)^b)
    __builtin_abort();
}

int main(void)
{
  checkf(0, 0);
  checkf(0, 1);
  checkf(1, 1);
  checkf(1, 0);
  return 0;
}
