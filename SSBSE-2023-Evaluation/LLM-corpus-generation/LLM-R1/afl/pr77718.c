// Modification timestamp: 2023-08-14 15:51:50
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr77718.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char a[64] __attribute__((aligned (8)));

__attribute__((noinline, noclone)) int
foo (char* a1)
{
  return __builtin_memcmp ("bbbbbb", a1, 6);
}

__attribute__((noinline, noclone)) int
bar (char* a1)
{
  return __builtin_memcmp (a1, "bbbbbb", 6);
}

int
main (int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  char a[64] __attribute__((aligned (8)));
  __builtin_memset (a, 'a', sizeof (a));
  if (((foo (argv[1]) < 0) ^ ('a' > 'b'))
      || ((bar (a) < 0) ^ ('a' < 'b')))
    __builtin_abort ();
    
  return 0;
}
