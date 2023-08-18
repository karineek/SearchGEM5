// Modification timestamp: 2023-08-14 15:25:07
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr53688.c

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char headline[256];
struct hdr {
  char part1[9];
  char part2[8];
} p;

void __attribute__((noinline,noclone))
init()
{
  __builtin_memcpy (p.part1, "FOOBARFOO", sizeof (p.part1));
  __builtin_memcpy (p.part2, "SPEC CPU", sizeof (p.part2));
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  char *x;
  int c;
  init();
  __builtin_memcpy (&headline[0], p.part1, sizeof(p.part1));
  c = sizeof(p.part1);
  x = &headline[0];
  x = x + c;
  __builtin_memset (x, ' ', sizeof(headline) - c);
  __builtin_memcpy (&headline[sizeof(p.part1)], p.part2, sizeof(p.part2));
  c = sizeof(p.part1) + sizeof(p.part2);
  x = &headline[0];
  x = x + c;
  __builtin_memset (x, ' ', sizeof(headline) - c);
  if (headline[sizeof(p.part1)] != 'S')
    __builtin_abort ();
  return 0;
}
