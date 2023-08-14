// Modification timestamp: 2023-08-14 12:59:26
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20041019-1.c

#include <stdio.h>
#include <stdlib.h>

int test_store_ccp(int i, int a, int b, int c) {
  int *p;

  if (i < 5)
    p = &a;
  else if (i > 8)
    p = &b;
  else
    p = &c;

  *p = 10;
  b = 3;

  /* STORE-CCP was wrongfully propagating 10 into *p.  */
  return *p + 2;
}

int test_store_copy_prop(int i, int a, int b, int c) {
  int *p;

  if (i < 5)
    p = &a;
  else if (i > 8)
    p = &b;
  else
    p = &c;

  *p = i;
  b = i + 1;

  /* STORE-COPY-PROP was wrongfully propagating i into *p.  */
  return *p;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int x = atoi(argv[1]);
  int a, b, c;

  x = test_store_ccp(x, a, b, c);
  if (x == 12)
    abort();

  x = test_store_copy_prop(x, a, b, c);
  if (x == x)
    abort();

  return 0;
}
