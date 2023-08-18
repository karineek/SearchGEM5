// Modification timestamp: 2023-08-14 14:17:53
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/compare-3.c

#include <stdio.h>

void link_error0() {}
void link_error1() {}

void test1(int x, int y) {
  if ((x == y) && (x != y))
    link_error0();
}

void test2(int x, int y) {
  if ((x < y) && (x > y))
    link_error0();
}

void test3(int x, int y) {
  if ((x < y) && (y < x))
    link_error0();
}

void test4(int x, int y) {
  if ((x == y) || (x != y)) {
  } else {
    link_error1();
  }
}

void test5(int x, int y) {
  if ((x >= y) || (x < y)) {
  } else {
    link_error1();
  }
}

void test6(int x, int y) {
  if ((x <= y) || (y < x)) {
  } else {
    link_error1();
  }
}

void all_tests(int x, int y) {
  test1(x, y);
  test2(x, y);
  test3(x, y);
  test4(x, y);
  test5(x, y);
  test6(x, y);
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <x> <y>\n", argv[0]);
    return 1;
  }

  int x = atoi(argv[1]);
  int y = atoi(argv[2]);

  all_tests(x, y);

  return 0;
}

//Note: The `link_error0` and `link_error1` functions are declared in the code, but they are not defined. You will need to provide their definitions or remove them if they are not needed.