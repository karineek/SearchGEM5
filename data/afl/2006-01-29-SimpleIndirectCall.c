
// Modification timestamp: 2023-08-10 15:14:18
// Original Source: https://github.com/llvm/llvm-test-suite

#include <stdio.h>
#include <stdlib.h>

void hello(int argc, char **argv) {
  printf("Hello, world!\n");
}

void goodbye(int argc, char **argv) {
  printf("Goodbye, world!\n");
}

int main(int argc, char **argv) {
  void (*f)(int, char **) = (argc > 1) ? &hello : &goodbye;
  f(argc, argv);
  return 0;
}
