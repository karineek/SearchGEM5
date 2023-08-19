// Modification timestamp: 2023-08-14 12:09:38
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20020201-1.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void exit(int);

unsigned char cx;
unsigned short sx;
unsigned int ix;
unsigned long lx;
unsigned long long Lx;

int main(int argc, char *argv[]) {
  if (argc < 7) {
    printf("Usage: %s <cx> <sx> <ix> <lx> <Lx>\n", argv[0]);
    return 1;
  }

  cx = atoi(argv[1]);
  sx = atoi(argv[2]);
  ix = atoi(argv[3]);
  lx = atoi(argv[4]);
  Lx = atoi(argv[5]);

  unsigned char cy;
  unsigned short sy;
  unsigned int iy;
  unsigned long ly;
  unsigned long long Ly;

  cy = cx / 6;
  if (cy != 1)
    abort();
  cy = cx % 6;
  if (cy != 1)
    abort();

  sy = sx / 6;
  if (sy != 2)
    abort();
  sy = sx % 6;
  if (sy != 2)
    abort();

  iy = ix / 6;
  if (iy != 3)
    abort();
  iy = ix % 6;
  if (iy != 3)
    abort();

  ly = lx / 6;
  if (ly != 4)
    abort();
  ly = lx % 6;
  if (ly != 4)
    abort();

  Ly = Lx / 6;
  if (Ly != 5)
    abort();
  Ly = Lx % 6;
  if (Ly != 5)
    abort();

  exit(0);
}


Please note that the program now expects command-line arguments for `cx`, `sx`, `ix`, `lx`, and `Lx`.