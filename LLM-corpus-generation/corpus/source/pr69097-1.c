// Modification timestamp: 2023-08-14 15:48:17
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr69097-1.c
#include <stdio.h>
#include <stdlib.h>

int a, b;
unsigned int c;

int main(int argc, char* argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int d = atoi(argv[1]);
  b = ~(~a + (~d | b));
  a = ~(~c >> b);
  c = a % b;
  return 0;
}

//Note: Since the original code didn't have any command-line arguments, I added the necessary check in the main function.