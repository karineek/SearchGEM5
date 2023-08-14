// Modification timestamp: 2023-08-14 13:20:31
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20120427-2.c

#include <stdio.h>
#include <stdlib.h>

typedef struct sreal
{
  unsigned sig;   /* Significant.  */
  int exp;        /* Exponent.  */
} sreal;

int sreal_compare(sreal *a, sreal *b)
{
  if (a->exp > b->exp)
    return 1;
  if (a->exp < b->exp)
    return -1;
  if (a->sig > b->sig)
    return 1;
  if (a->sig < b->sig)
    return -1;
  return 0;
}

sreal a[] = {
  { 0, 0 },
  { 1, 0 },
  { 0, 1 },
  { 1, 1 }
};

int main(int argc, char *argv[]) {
  int i, j;
  for (i = 0; i <= 3; i++) {
    for (j = 0; j < 3; j++) {
      if (i < j && sreal_compare(&a[i], &a[j]) != -1) abort();
      if (i == j && sreal_compare(&a[i], &a[j]) != 0) abort();
      if (i > j && sreal_compare(&a[i], &a[j]) != 1) abort();
    }
  }
  return 0;
}
