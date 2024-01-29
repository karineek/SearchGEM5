// Modification timestamp: 2023-08-14 15:25:22
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr54937.c

#include <stdlib.h>

void exit(int);
void abort(void);
int a[1];
void (*terminate_me)(int);

__attribute__((noinline,noclone))
void t(int c)
{
  int i;
  for (i = 0; i < c; i++)
  {
    if (i)
      terminate_me(0);
    a[i] = 0;
  }
}

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int c = atoi(argv[1]);
  terminate_me = exit;
  t(c);
  abort();
}
