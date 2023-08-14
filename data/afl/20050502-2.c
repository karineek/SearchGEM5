// Modification timestamp: 2023-08-14 13:03:38
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20050502-2.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef __SIZE_TYPE__ size_t;
extern int memcmp (const char *, const char *, size_t);
extern void abort ();

void foo(char *x, char *i) {
  x[i + i] = '\0';
}

void bar(char *x, char *i) {
  x[i + i + i + i] = '\0';
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  char x[] = "IJKLMNOPQR";
  char *i = argv[1];
  
  foo(x, i);
  if (memcmp(x, "IJKL\0NOPQR", sizeof x) != 0)
    abort();
  
  x[4] = 'M';
  bar(x, i);
  if (memcmp(x, "IJKLMNOP\0R", sizeof x) != 0)
    abort();
  
  return 0;
}

