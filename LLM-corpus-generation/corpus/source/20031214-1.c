// Modification timestamp: 2023-08-14 12:50:52
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20031214-1.c
#include <stdlib.h>

#include <stdio.h>

struct
{
  double a;
  int n[2];
} g = { 0., { 1, 2}};

int k = 0;

void b(int *j)
{
}

int main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int j;

  for (j = 0; j < atoi(argv[1]); j++)
    k = (k > g.n[j]) ? k : g.n[j];

  k++;
  b(&j);

  return 0;
}
