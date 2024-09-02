// Modification timestamp: 2023-08-14 14:46:08
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr22098-2.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void exit(int);
typedef __UINTPTR_TYPE__ uintptr_t;

int main(int argc, char *argv[]) {
  int a = 0;
  int *p;
  uintptr_t b;
  b = (uintptr_t)(p = &(int[]){0, 1, 2}[1]);
  if (*p != 1 || *(int *)b != 1)
    abort();
  exit(0);
}
