// Modification timestamp: 2023-08-14 16:00:01
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr84478.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long poolptr;
unsigned char *strpool;
static const char *poolfilearr[] = {
  "mu",
  "",
#define A argv[1]
#define B A "xx", A A "xxx", A A A A A
#define C B B B B B B B B B B
#define D C C C C C C C C C C
  D C C C C C C C B B B
 ((void *)0)
};

__attribute__((noipa)) long
makestring (void)
{
  return 1;
}

__attribute__((noipa)) long
loadpoolstrings (long spare_size)
{
  const char *s;
  long g = 0;
  int i = 0, j = 0;
  while ((s = poolfilearr[j++]))
    {
      int l = strlen(s);
      i += l;
      if (i >= spare_size) return 0;
      while (l-- > 0) strpool[poolptr++] = *s++;
      g = makestring ();
    }
  return g;
}

int
main (int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  strpool = malloc(4000);
  if (!strpool)
    return 0;
  asm volatile ("" : : : "memory");
  volatile int r = loadpoolstrings(4000);
  free(strpool);
  return 0;
}