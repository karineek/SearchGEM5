// Modification timestamp: 2023-08-14 16:52:44
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/struct-ini-2.c

#include <stdio.h>
#include <stdlib.h>

struct MyStruct {
  int a:4;
  int :4; // Unused
  int b:4;
  int c:4;
} x = {2, 0, 3, 4};

int main(int argc, char *argv[]) {
  if (x.a != atoi(argv[1]))
    abort();
  if (x.b != atoi(argv[2]))
    abort();
  if (x.c != atoi(argv[3]))
    abort();
  exit(0);
}
