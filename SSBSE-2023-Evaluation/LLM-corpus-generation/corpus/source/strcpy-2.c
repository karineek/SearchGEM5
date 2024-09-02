// Modification timestamp: 2023-08-14 16:14:18
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/strcpy-2.c

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STRING "Hi!THE"

const char a[] = STRING;

void f(char *a) __attribute__((noinline));
void f(char *a)
{
  strcpy(a, STRING);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int i;
  char b[sizeof(a)] = {};
  f(b);
  for (i = 0; i < sizeof(b); i++) {
    if (a[i] != b[i])
      abort();
  }
  return 0;
}
