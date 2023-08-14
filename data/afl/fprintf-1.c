// Modification timestamp: 2023-08-14 14:27:10
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/fprintf-1.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

#define test(ret, args...) \
  fprintf (stdout, args);      \
  if (fprintf (stdout, args) != ret)  \
    abort ();
  test (5, "hello");
  test (6, "hello\n");
  test (1, "a");
  test (0, "");
  test (5, "%s", "hello");
  test (6, "%s", "hello\n");
  test (1, "%s", "a");
  test (0, "%s", "");
  test (1, "%c", 'x');
  test (7, "%s\n", "hello\n");
  test (2, "%d\n", atoi(argv[1]));
  return 0;
}
