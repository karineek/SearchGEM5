// Modification timestamp: 2023-08-14 16:53:27
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/switch-1.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

int foo(int x) {
  switch (x) {
    case 4:
    case 6:
    case 9:
    case 11:
      return 30;
  }
  return 31;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int i, r;
  int x = atoi(argv[1]);

  for (i = -1; i < 66; i++) {
    r = foo(i);
    if (i == x) {
      if (r != 30)
        abort();
    } else if (r != 31) {
      abort();
    }
  }

  return 0;
}
