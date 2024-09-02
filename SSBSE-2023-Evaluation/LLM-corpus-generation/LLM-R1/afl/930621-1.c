// Modification timestamp: 2023-08-14 13:34:36
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/930621-1.c

#include <stdio.h>
#include <stdlib.h>

#if __INT_MAX__ < 2147483647
int main(void) {
  exit(0);
}
#else
void f() {
  struct {
    int x : 18;
    int y : 14;
  } foo;

  foo.x = atoi(argv[1]);
  foo.y = atoi(argv[2]);

  printf("%d\n", foo.y);
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <value1> <value2>\n", argv[0]);
    return 1;
  }

  f();
  return 0;
}
#endif
