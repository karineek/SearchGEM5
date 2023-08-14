// Modification timestamp: 2023-08-14 14:34:49
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/medce-1.c

extern void abort (void);
extern void link_error (void);

static int ok = 0;

void bar (void)
{
  ok = 1;
}

void foo(int x)
{
  switch (x)
  {
  case 0:
    if (0)
    {
      link_error();
  case 1:
      bar();
    }
  }
}

int main()
{
  foo (1);
  if (!ok)
    abort ();
  return 0;
}
