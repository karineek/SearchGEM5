// Modification timestamp: 2023-08-14 13:02:30
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20050218-1.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef __SIZE_TYPE__ size_t;
extern size_t strlen (const char *s);
extern int strncmp (const char *s1, const char *s2, size_t n);
extern void abort (void);

const char *a[16] = { "a", "bc", "de", "fgh" };

int foo(char *x, const char *y, size_t n) {
  size_t i, j = 0;
  for (i = 0; i < n; i++) {
    if (strncmp(x + j, a[i], strlen(a[i])) != 0)
      return 2;
    j += strlen(a[i]);
    if (y)
      j += strlen(y);
  }
  return 0;
}

int main(int argc, char *argv[]) {
  if (argc != 4) {
    printf("Usage: %s <value1> <value2> <value3>\n", argv[0]);
    return 1;
  }

  char* x = argv[1];
  const char* y = (const char*) 0;
  size_t n = atoi(argv[3]);

  if (foo(x, y, n) != 0)
    abort();
  return 0;
}
