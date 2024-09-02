// Modification timestamp: 2023-08-14 13:30:43
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/921019-1.c

#include <stdio.h>
#include <stdlib.h>

void *foo[] = { (void *)("X" + 0) };

int main(int argc, char *argv[]) {
  if (((char *)foo[0])[0] != 'X') {
    abort();
  }
  exit(0);
}

