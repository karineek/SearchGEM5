// Modification timestamp: 2023-08-14 15:44:17
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr65427.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int V __attribute__((vector_size(8 * sizeof(int))));
V a, b, c, d, e, f;

__attribute__((noinline, noclone))
void foo(int x, int y, V* result)
{
  do
  {
    if (x)
      *result = a ^ c;
    else
      *result = a ^ b;
  } while (y);
}

int main(int argc, char *argv[])
{
  if (argc != 1)
  {
    printf("Usage: %s\n", argv[0]);
    return 1;
  }

  a = (V){1, 2, 3, 4, 5, 6, 7, 8};
  b = (V){0x40, 0x80, 0x40, 0x80, 0x40, 0x80, 0x40, 0x80};
  e = (V){0x41, 0x82, 0x43, 0x84, 0x45, 0x86, 0x47, 0x88};
  foo(0, 0, &d);
  if (memcmp(&d, &e, sizeof(V)) != 0)
    abort();
  c = (V){0x80, 0x40, 0x80, 0x40, 0x80, 0x40, 0x80, 0x40};
  f = (V){0x81, 0x42, 0x83, 0x44, 0x85, 0x46, 0x87, 0x48};
  foo(1, 0, &d);
  if (memcmp(&d, &f, sizeof(V)) != 0)
    abort();
  return 0;
}
