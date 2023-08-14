// Modification timestamp: 2023-08-14 13:28:59
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/920721-4.c

#include <stdio.h>
#include <stdlib.h>

int try(int num) {
  __label__ lab1, lab2, lab3, lab4, lab5, lab6, default_lab;

  void *do_switch(int num) {
    switch (num) {
      case 1:
        return &&lab1;
      case 2:
        return &&lab2;
      case 3:
        return &&lab3;
      case 4:
        return &&lab4;
      case 5:
        return &&lab5;
      case 6:
        return &&lab6;
      default:
        return &&default_lab;
    }
  }

  goto *do_switch(num);

lab1:
  return 1;

lab2:
  return 2;

lab3:
  return 3;

lab4:
  return 4;

lab5:
  return 5;

lab6:
  return 6;

default_lab:
  return -1;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int i = atoi(argv[1]);
  for (int j = 1; j <= i; j++) {
    if (try(j) != j)
      abort();
  }
  exit(0);
}
