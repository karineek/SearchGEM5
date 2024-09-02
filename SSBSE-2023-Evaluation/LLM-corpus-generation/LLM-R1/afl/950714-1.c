// Modification timestamp: 2023-08-14 13:43:12
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/950714-1.c

#include <stdio.h>
#include <stdlib.h>

int array[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int i, j;
  int *p;

  int x = atoi(argv[1]);

  for (i = 0; i < x; i++)
    for (p = &array[0]; p != &array[9]; p++)
      if (*p == i)
	goto label;

 label:
  if (i != 1)
    abort ();
  exit (0);
}
