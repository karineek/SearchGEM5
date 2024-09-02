// Modification timestamp: 2023-08-14 13:20:49
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20120808-1.c

#include <stdio.h>
#include <stdlib.h>

extern void exit (int);
extern void abort (void);

volatile int i;
unsigned char *volatile cp;
unsigned char d[32] = { 0 };

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int value = atoi(argv[1]);
  int j;
  unsigned char c[32] = { 0 };
  unsigned char *p = d + i;
  for (j = 0; j < 30; j++) {
    int x = 0xff;
    int y = *++p;
    switch (j) {
    case 1: x ^= 2; break;
    case 2: x ^= 4; break;
    case 25: x ^= 1; break;
    default: break;
    }
    c[j] = y | x;
    cp = p;
  }
  if (c[0] != 0xff
      || c[1] != 0xfd
      || c[2] != 0xfb
      || c[3] != 0xff
      || c[4] != 0xff
      || c[25] != 0xfe
      || cp != d + 30)
    abort ();
  exit (value);
}
