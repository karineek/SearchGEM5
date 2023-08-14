// Modification timestamp: 2023-08-14 14:05:32
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/bf-layout-1.c

#include <stdio.h>
#include <stdlib.h>

struct {
  long f8:8;
  long f24:24;
} a;

struct {
  long f32:32;
} b;

int main(int argc, char *argv[]) {
  if (sizeof(a) != sizeof(b)) {
    abort();
  }
  exit(0);
}
