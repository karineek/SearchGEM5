// Modification timestamp: 2023-08-14 13:12:14
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20071211-1.c

#include <stdio.h>
#include <stdlib.h>

extern void abort() __attribute__ ((noreturn));

struct s
{
  unsigned long long f1 : 40;
#if(__SIZEOF_INT__ >= 4)
  unsigned int f2 : 24;
#else
  unsigned long int f2 : 24;
#endif
} sv;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int f2;
  sv.f2 = atoi(argv[1]);
  __asm__ volatile ("" : : : "memory");
  ++sv.f2;
  f2 = sv.f2;
  if (f2 != 0)
    abort();
  return 0;
}
