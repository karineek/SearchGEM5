// Modification timestamp: 2023-08-14 13:56:49
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/991016-1.c

#include <stdio.h>
#include <stdlib.h>

typedef int T0;
typedef long T1;
typedef long long T2;

int doit(int sel, int n, void *p) {
  T0 * const p0 = p;
  T1 * const p1 = p;
  T2 * const p2 = p;

  switch (sel) {
    case 0:
      do
        *p0 += *p0;
      while (--n);
      return *p0 == 0;

    case 1:
      do
        *p1 += *p1;
      while (--n);
      return *p1 == 0;

    case 2:
      do
        *p2 += *p2;
      while (--n);
      return *p2 == 0;

    default:
      abort ();
  }
}

int main(int argc, char *argv[]) {
  T0 v0;
  T1 v1;
  T2 v2;

  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  v0 = atoi(argv[1]);
  v1 = atoi(argv[1]);
  v2 = atoi(argv[1]);

  doit(0, 5, &v0);
  doit(1, 5, &v1);
  doit(2, 5, &v2);

  if (v0 != 32) abort ();
  if (v1 != 32) abort ();
  if (v2 != 32) abort ();

  exit (0);
}

