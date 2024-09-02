// Modification timestamp: 2023-08-14 14:00:05
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/anon-1.c

#include <stdio.h>
#include <stdlib.h>

struct
{
  int x;
  struct
  {
    int a;
    union
    {
      int b;
    };
  };
} foo;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  foo.b = atoi(argv[1]);
  foo.a = atoi(argv[2]);

  if (foo.b != atoi(argv[3]))
    abort();

  return 0;
}
