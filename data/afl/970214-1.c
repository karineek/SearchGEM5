// Modification timestamp: 2023-08-14 13:48:21
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/970214-1.c

#include <stdio.h>
#include <stdlib.h>

#define L 1

int main(int argc, char *argv[]) {
  exit(L'1' != L'1');
}
