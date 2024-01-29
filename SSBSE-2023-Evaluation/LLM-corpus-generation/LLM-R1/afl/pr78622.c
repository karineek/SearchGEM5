// Modification timestamp: 2023-08-14 15:53:02
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr78622.c

#include <stdio.h>
#include <stdlib.h>

__attribute__((noinline, noclone)) int foo(int x) {
  if (x < 4096 + 8 || x >= 4096 + 256 + 8)
    return -1;

  char buf[5];
  int n = __builtin_snprintf(buf, sizeof(buf), "%hhd", x + 1);
  printf("\"%hhd\" => %i\n", x + 1, n);
  return n;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  if (__SCHAR_MAX__ != 127 || __CHAR_BIT__ != 8 || __SIZEOF_INT__ != 4)
    return 0;
  
  int x = atoi(argv[1]);
  if (foo(x) != 1 || foo(x + 23) != 2 || foo(x + 127) != 3 || foo(x + 128) != 4 || foo(x + 240) != 3 || foo(x + 248) != 2 || foo(x + 255) != 2 || foo(x + 256) != 1)
    abort();

  return 0;
}

