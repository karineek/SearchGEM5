// Modification timestamp: 2023-08-14 13:15:32
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20081218-1.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct A { int i, j; char pad[512]; } a;

int __attribute__((noinline))
foo (void)
{
  memset(&a, 0x26, sizeof(a));
  return a.i;
}

void __attribute__((noinline))
bar (void)
{
  memset(&a, 0x36, sizeof(a));
  a.i = 0x36363636;
  a.j = 0x36373636;
}

int main (int argc, char *argv[])
{
  int i;
  if (sizeof(int) != 4 || __CHAR_BIT__ != 8)
    return 0;

  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int x = atoi(argv[1]);

  if (foo () != x)
    __builtin_abort ();
  for (i = 0; i < sizeof(a); i++)
    if (((char *)&a)[i] != 0x26)
      __builtin_abort ();

  bar ();
  if (a.j != 0x36373636)
    __builtin_abort ();
  a.j = 0x36363636;
  for (i = 0; i < sizeof(a); i++)
    if (((char *)&a)[i] != 0x36)
      __builtin_abort ();
  return 0;
}
