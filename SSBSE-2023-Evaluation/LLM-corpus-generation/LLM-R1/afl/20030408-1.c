// Modification timestamp: 2023-08-14 12:45:54
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20030408-1.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

struct foo {
  char a, b, c, d, e, f, g, h, i, j;
};

int test1 (char a0[], char a1[])
{
  char buffer[8];
  __builtin_memcpy(buffer, a0, 8);
  if (buffer[0] != a1[0] || buffer[1] != a1[1]
      || buffer[2] != a1[2] || buffer[3] != a1[3]
      || buffer[4] != a1[4] || buffer[5] != a1[5]
      || buffer[6] != a1[6] || buffer[7] != a1[7])
    abort();
  return 0;
}

int test2 (char a0[], char a1[])
{
  char buffer[10];
  __builtin_memcpy(buffer, a0, 10);
  if (buffer[0] != a1[0] || buffer[1] != a1[1]
      || buffer[2] != a1[2] || buffer[3] != a1[3]
      || buffer[4] != a1[4] || buffer[5] != a1[5]
      || buffer[6] != a1[6] || buffer[7] != a1[7]
      || buffer[8] != a1[8] || buffer[9] != a1[9])
    abort();
  return 0;
}

int test3 (char a0[], char a1[])
{
  struct foo X = { .a = a1[0], .c = a1[2], .e = a1[4], .g = a1[6], .i = a1[8] };
  char buffer[10];
  __builtin_memcpy(buffer, &X, 10);
  if (buffer[0] != a1[0] || buffer[1] != a1[1]
      || buffer[2] != a1[2] || buffer[3] != a1[3]
      || buffer[4] != a1[4] || buffer[5] != a1[5]
      || buffer[6] != a1[6] || buffer[7] != a1[7]
      || buffer[8] != a1[8] || buffer[9] != a1[9])
    abort();
  return 0;
}

int test4 (char a0[], char a1[])
{
  struct foo X = { .b = a1[1], .d = a1[3], .f = a1[5], .h = a1[7], .j = a1[9] };
  char buffer[10];
  __builtin_memcpy(buffer, &X, 10);
  if (buffer[0] != a1[0] || buffer[1] != a1[1]
      || buffer[2] != a1[2] || buffer[3] != a1[3]
      || buffer[4] != a1[4] || buffer[5] != a1[5]
      || buffer[6] != a1[6] || buffer[7] != a1[7]
      || buffer[8] != a1[8] || buffer[9] != a1[9])
    abort();
  return 0;
}

int main (int argc, char *argv[])
{
  if (argc != 11) {
    printf("Usage: %s a0 a1 a2 a3 a4 a5 a6 a7 a8 a9\n", argv[0]);
    return 1;
  }

  char a0[8] = { argv[1][0], argv[2][0], argv[3][0], argv[4][0], argv[5][0], argv[6][0], argv[7][0], argv[8][0] };
  char a1[10] = { argv[1][0], argv[2][0], argv[3][0], argv[4][0], argv[5][0], argv[6][0], argv[7][0], argv[8][0], argv[9][0], argv[10][0] };

  test1(a0, a1);
  test2(a0, a1);
  test3(a0, a1);
  test4(a0, a1);
  return 0;
}
