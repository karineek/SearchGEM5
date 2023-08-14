// Modification timestamp: 2023-08-14 14:42:00
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/p18298.c

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

extern void abort (void);

char s[2048] = "a";

inline bool foo(const char *str) {
  return !strcmp(s, str);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int i = 0;

  while (!(foo(argv[1]))) {
    i++;
    s[0] = '\0';
    if (i > 2)
      abort();
  }

  return 0;
}
