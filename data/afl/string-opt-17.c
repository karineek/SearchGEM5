// Modification timestamp: 2023-08-14 16:15:18
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/string-opt-17.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t test1(char* s, size_t i, int check2_result) {
  strcpy(s, "foobarbaz" + i++);
  return i;
}

size_t check2(int check2_result) {
  static size_t r = 5;
  if (r != 5)
    abort();
  return ++r;
}

void test2(char* s, int check2_result) {
  strcpy(s, "foobarbaz" + check2(check2_result));
}

int main(int argc, char* argv[]) {
  char buf[10];
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }
  if (test1(buf, 7, atoi(argv[1])) != 8 || memcmp(buf, "az", 3))
    abort();
  test2(buf, atoi(argv[1]));
  if (memcmp(buf, "baz", 4))
    abort();
  exit(0);
}
