// Modification timestamp: 2023-08-02 16:45:00
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00004.c

#include <stdio.h>

int main() {
  int x;
  int *p;
  
  x = 4;
  p = &x;
  *p = 0;

  return *p;
}
