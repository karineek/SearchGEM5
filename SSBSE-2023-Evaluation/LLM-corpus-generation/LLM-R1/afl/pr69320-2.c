// Modification timestamp: 2023-08-14 15:48:37
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr69320-2.c

#include <stdlib.h>

int a, *c, d, e, g, f;
short b;

int fn1(int argc, char* argv[]) {
  int h = atoi(argv[1]) != 10;
  if (h > atoi(argv[2]))
    asm volatile("" : : : "memory");
  if (h == 10) {
    int* i = 0;
    a = 0;
    for (; a < 7; a++)
      for (; *i;)
        ;
  } else {
    b = atoi(argv[3]) / h;
    return atoi(argv[4]);
  }
  c = &h;
  abort();
}

int main(int argc, char* argv[]) {
  if (argc != 5) {
    printf("Usage: %s <value1> <value2> <value3> <value4>\n", argv[0]);
    return 1;
  }

  fn1(argc, argv);
  exit(0);
}

