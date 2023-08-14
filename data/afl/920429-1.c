// Modification timestamp: 2023-08-14 13:26:09
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/920429-1.c

#include <stdio.h>
#include <stdlib.h>

typedef unsigned char t;
int i, j;

t* f(t* p) {
  t c;
  c = *p++;
  i = ((c & 2) ? 1 : 0);
  j = (c & 7) + 1;
  return p;
}

int main(int argc, char* argv[]) {
  if (argc != 2) {
    printf("Usage: %s <string>\n", argv[0]);
    return 1;
  }

  t* p0 = argv[1];
  t* p1;
  p1 = f(p0);
  if (p0 + 1 != p1)
    abort();
  exit(0);
}
