// Modification timestamp: 2023-08-14 13:06:54
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20060905-1.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

volatile char s[256][3];

char g;

static void dummy(char a)
{
  g = a;
}

static int foo(char s[][3], int size)
{
  int i, j=0;

  for (i = 0; i < size; i++)
    if (i >= size / 2 && i < size)
      {
        dummy(s[i - size / 2][0]);
        ++j;
      }

  return j;
}

int main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <size>\n", argv[0]);
    return 1;
  }

  int size = atoi(argv[1]);

  if (size != 256) {
    printf("Size must be 256\n");
    return 1;
  }

  if (foo(s, size) != size / 2) {
    abort();
  }

  return 0;
}
