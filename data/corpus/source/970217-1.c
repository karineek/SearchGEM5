// Modification timestamp: 2023-08-14 13:48:29
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/970217-1.c

#include <stdio.h>
#include <stdlib.h>

int sub(int i, int array[]) {
  return i;
}

int main(int argc, char *argv[]) {
  int array[10];

  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int result = sub(atoi(argv[1]), array);
  exit(result != atoi(argv[2]));
}

//Note: I assumed that the value to compare with in the `exit()` function is passed as a command line argument.