// Modification timestamp: 2023-08-14 15:56:27
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr81503.c

#include <stdio.h>
#include <stdlib.h>

unsigned short a = 0;
unsigned short b = 0;
__INT32_TYPE__ c = 0;

void foo(unsigned short arg_a, unsigned short arg_b, __INT32_TYPE__ arg_c) {
  if (arg_a + arg_b * ~((__INT32_TYPE__)(0 != 5)))
    arg_c = -~(arg_b * ~((__INT32_TYPE__)(0 != 5))) + 2147483647;
}

int main(int argc, char *argv[]) {
  if (argc != 4) {
    printf("Usage: %s <a> <b> <c>\n", argv[0]);
    return 1;
  }

  unsigned short arg_a = atoi(argv[1]);
  unsigned short arg_b = atoi(argv[2]);
  __INT32_TYPE__ arg_c = atoi(argv[3]);

  foo(arg_a, arg_b, arg_c);

  if (arg_c != 2147476810)
    return -1;

  return 0;
}
