// Modification timestamp: 2023-08-14 13:20:19
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20120427-1.c

#include <stdio.h>
#include <stdlib.h>

typedef struct sreal
{
  unsigned sig;    /* Significant.  */
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
  return -(a->sig < b->sig);
}

int main(int argc, char *argv[]) {
  sreal a[] = {
   { atoi(argv[1]), atoi(argv[2]) },
   { atoi(argv[3]), atoi(argv[4]) },
   { atoi(argv[5]), atoi(argv[6]) },
   { atoi(argv[7]), atoi(argv[8]) }
  };

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


Note: You need to provide 8 command-line arguments to pass the values for `sreal` structure elements when running the program.