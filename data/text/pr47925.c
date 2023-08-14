// Modification timestamp: 2023-08-14 15:16:08
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr47925.c
struct s { volatile struct s *next; };

void __attribute__((noinline))
bar (int ignored, int n)
{
  asm volatile ("");
}

int __attribute__((noinline))
foo (volatile struct s *ptr, int n)
{
  int i;

  bar (0, n);
  for (i = 0; i < n; i++)
    ptr = ptr->next;
}

int main (void)
{
  volatile struct s rec = { &rec };
  foo (&rec, 10);
  return 0;
}
