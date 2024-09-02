// Modification timestamp: 2023-08-14 15:36:39
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr59388.c

/* PR tree-optimization/59388 */

#include <stdio.h>

int a;
struct S { unsigned int f:1; } b;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }
  
  a = (atoi(argv[1]) < b.f) | b.f;
  return a;
}
