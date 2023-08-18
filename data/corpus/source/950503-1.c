// Modification timestamp: 2023-08-14 13:41:44
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/950503-1.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int tmp;
  unsigned long long utmp1, utmp2;

  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  tmp = atoi(argv[1]);

  utmp1 = (~((unsigned long long) 0)) >> tmp;
  utmp2 = (~((unsigned long long) 0)) >> 16;

  if (utmp1 != utmp2)
    abort ();
  exit (0);
}
