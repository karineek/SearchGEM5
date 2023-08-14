// Modification timestamp: 2023-08-14 15:16:08
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr47925.c

#include <stdio.h>

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

int main (int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int n = atoi(argv[1]);
  volatile struct s rec = { &rec };
  foo (&rec, n);
  return 0;
}
