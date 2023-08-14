// Modification timestamp: 2023-08-14 12:58:27
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20040709-3.c

/* PR rtl-optimization/68205 */
/* { dg-require-effective-target int32plus } */
/* { dg-additional-options "-fno-common" } */

#include "20040709-2.c"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int x = atoi(argv[1]);
  int y;
  baz(x, &y);
  return y;
}
