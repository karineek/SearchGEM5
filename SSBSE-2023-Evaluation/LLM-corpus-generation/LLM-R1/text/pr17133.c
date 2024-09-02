// Modification timestamp: 2023-08-14 14:43:36
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr17133.c
extern void abort (void);

int foo = 0;
void *bar = 0;
unsigned int baz = 100;

void *pure_alloc ()
{
  void *res;

  while (1)
    {
      res = (void *) ((((unsigned int) (foo + bar))) & ~1);
      foo += 2;
      if (foo < baz)
        return res;
      foo = 0;
    }
}

int main ()
{
  pure_alloc ();
  if (!foo)
    abort ();
  return 0;
}
