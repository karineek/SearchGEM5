// Modification timestamp: 2023-08-14 13:36:20
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/930930-1.c

#include <stdio.h>
#include <stdlib.h>

__extension__ typedef __PTRDIFF_TYPE__ ptr_t;

ptr_t *wm_TR;
ptr_t *wm_HB;
ptr_t *wm_SPB;

ptr_t mem[100];

void f(ptr_t *mr_TR, ptr_t *mr_SPB, ptr_t *mr_HB, ptr_t *reg1, ptr_t *reg2) {
  ptr_t *x = mr_TR;

  for (;;) {
    if (reg1 < reg2)
      goto out;
    if ((ptr_t *)*reg1 < mr_HB && (ptr_t *)*reg1 >= mr_SPB)
      *--mr_TR = *reg1;
    reg1--;
  }
out:

  if (x != mr_TR)
    abort();
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  ptr_t *mr_TR = (ptr_t *)atoi(argv[1]);
  ptr_t *mr_SPB = (ptr_t *)atoi(argv[2]);
  ptr_t *mr_HB = (ptr_t *)atoi(argv[3]);
  ptr_t *reg1 = (ptr_t *)atoi(argv[4]);
  ptr_t *reg2 = (ptr_t *)atoi(argv[5]);

  mem[99] = (ptr_t)mem;
  f(mem + 100, mem + 6, mem + 8, mem + 99, mem + 99);
  exit(0);
}
