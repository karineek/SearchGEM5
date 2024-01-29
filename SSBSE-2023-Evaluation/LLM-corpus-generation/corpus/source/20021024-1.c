// Modification timestamp: 2023-08-14 12:37:27
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20021024-1.c

#include <stdio.h>
#include <stdlib.h>

void exit(int);
void abort(void);

unsigned long long *cp, m;

void foo(void) {
}

void bar(unsigned rop, unsigned long long *r, int argc, char *argv[]) {
  unsigned rs1, rs2, rd;

top:
  rs2 = (rop >> 23) & 0x1ff;
  rs1 = (rop >> 9) & 0x1ff;
  rd = rop & 0x1ff;

  *cp = 1;
  m = r[rs1] + r[rs2];
  *cp = 2;
  foo();
  if (!rd)
    goto top;
  r[rd] = 1;
}

int main(int argc, char *argv[]) {
  static unsigned long long r[64];
  unsigned long long cr;
  cp = &cr;

  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  r[4] = atoi(argv[1]);
  r[8] = 11;
  bar((8 << 23) | (4 << 9) | 15, r, argc, argv);

  if (m != r[4] + 11)
    abort();
  exit(0);
}
