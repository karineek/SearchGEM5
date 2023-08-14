c
// Modification timestamp: 2023-08-10 15:49:31
// Original Source: https://github.com/llvm/llvm-test-suite

#include <stdio.h>

// Macro is needed for necessary coverage

#define gen_sw(a) _Generic(a, const char * : 1, default : 8, int : 123);

int main() {
  int i = 0;
  printf("%s\n", _Generic(i + (2L + 42), long
                          : "long", int
                          : "int", long long
                          : "long long"));
  return 0;
}
