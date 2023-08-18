// Modification timestamp: 2023-08-14 15:31:02
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr58570.c

#include <stdio.h>
#include <stdlib.h>

#pragma pack(1)
struct S {
  int f0:15;
  int f1:29;
};

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int e = atoi(argv[1]);
  int i;
  static struct S d[6];

  if (e) {
    d[i].f0 = atoi(argv[2]);
    d[i].f1 = atoi(argv[3]);
  }
  if (d[0].f1 != atoi(argv[4])) {
    __builtin_abort();
  }
  return 0;
}
