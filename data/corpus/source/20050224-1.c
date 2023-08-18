// Modification timestamp: 2023-08-14 13:02:42
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20050224-1.c

#include <stdio.h>

extern void abort (void);
void foo(int x, int y, int z);

int main(int argc, char *argv[]) {
  if (argc != 4) {
    printf("Usage: %s <x> <y> <z>\n", argv[0]);
    return 1;
  }

  int x = atoi(argv[1]);
  int y = atoi(argv[2]);
  int z = atoi(argv[3]);

  unsigned long a = 0xc0000000, b = 0xd0000000;
  unsigned long c = 0xc01bb958, d = 0xc0264000;
  unsigned long e = 0xc0288000, f = 0xc02d4378;

  unsigned long g;
  int h = 0, i = 0, j = 0;

  if (sizeof(unsigned long) < 4)
    return 0;

  for (g = a; g < b; g += 0x1000)
    if (g < c)
      h++;
    else if (g >= d && g < e)
      j++;
    else if (g < f)
      i++;

  foo(i, j, h);
  return 0;
}

// The original implementation of the foo function
void foo(int x, int y, int z) {
  if (x != 245 || y != 36 || z != 444)
    abort();
}


//Note: I've added a separate `foo` function declaration to avoid potential warnings.