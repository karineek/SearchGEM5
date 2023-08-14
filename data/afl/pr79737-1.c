// Modification timestamp: 2023-08-14 15:54:35
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr79737-1.c

#include <stdio.h>
#include <stdlib.h>

#pragma pack(1)
struct S {
  int32_t b;
  int32_t c;
  int32_t d;
  int32_t e;
  int32_t f;
} i;
int g, j, k;
static struct S h;

void foo(int argc, char *argv[]) {
  for (j = 0; j < 6; j++)
    k = 0;
  for (; k < 3; k++) {
    struct S m = { atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]), atoi(argv[5]) };
    h = m;
    if (g)
      i = m;
    h.e = 0;
  }
}

int main(int argc, char *argv[]) {
  if (argc != 6) {
    printf("Usage: %s <arg1> <arg2> <arg3> <arg4> <arg5>\n", argv[0]);
    return 1;
  }
  
  foo(argc, argv);
  if (h.e != 0)
    __builtin_abort ();
  return 0;
}
