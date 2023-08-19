// Modification timestamp: 2023-08-14 15:19:53
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr51447.c

#include <stdio.h>
#include <stdlib.h>

void abort(void) {
  printf("Aborted!\n");
  exit(1);
}

#ifdef __x86_64__
register void *ptr asm("rbx");
#else
void *ptr;
#endif

int main(int argc, char *argv[]) {
  __label__ nonlocal_lab;
  __attribute__((noinline, noclone)) void bar(void *func) {
    ptr = func;
    goto nonlocal_lab;
  }
  bar(&&nonlocal_lab);
  return 1;
nonlocal_lab:
  if (ptr != &&nonlocal_lab)
    abort();
  return 0;
}
