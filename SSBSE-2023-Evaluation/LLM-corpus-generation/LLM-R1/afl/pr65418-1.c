// Modification timestamp: 2023-08-14 15:43:56
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr65418-1.c

#include <stdio.h>
#include <stdlib.h>

__attribute__((noinline, noclone)) int
foo(int x) {
  if (x == atoi(argv[1]) || x == atoi(argv[2]) || x == atoi(argv[3]) || x == atoi(argv[4]))
    return 1;
  return 0;
}

int main(int argc, char *argv[]) {
  if (argc != 5) {
    printf("Usage: %s <arg1> <arg2> <arg3> <arg4>\n", argv[0]);
    return 1;
  }

  int i;
  for (i = atoi(argv[5]); i < atoi(argv[6]); i++) {
    if (foo(i) != (i == atoi(argv[1]) || i == atoi(argv[2]) || i == atoi(argv[3]) || i == atoi(argv[4]))) {
      printf("Error: mismatch found\n");
      return 1;
    }
  }

  return 0;
}

Note: This code is assuming that the command-line arguments are provided as `argc` and `argv`. The usage message is printed if the number of arguments is incorrect.