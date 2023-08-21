// Modification timestamp: 2023-08-14 14:26:30
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/enum-3.c

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void exit(int);

enum e {
  a = INT_MIN
};

int* p;
enum e* q;

int main(int argc, char* argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  enum e x = atoi(argv[1]);
  q = &x;
  if (*(1 ? q : p) > 0)
    abort();
  exit(0);
}
