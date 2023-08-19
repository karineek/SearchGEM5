// Modification timestamp: 2023-08-14 13:48:13
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/961213-1.c

#include <stdio.h>
#include <stdlib.h>

int g (unsigned long long int *v, int n, unsigned int a[], int b) {
  int cnt;
  *v = 0;

  for (cnt = 0; cnt < n; ++cnt)
    *v = *v * b + a[cnt];

  return n;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int res;
  unsigned int ar[] = { 10, 11, 12, 13, 14 };
  unsigned long long int v;

  res = g (&v, sizeof(ar)/sizeof(ar[0]), ar, atoi(argv[1]));
  
  if (v != 0xabcdeUL)
    abort ();

  exit (0);
}


Note that in the conversion, the value of `b` is taken from the command-line argument `argv[1]`.