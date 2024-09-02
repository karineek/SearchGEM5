// Modification timestamp: 2023-08-14 17:34:27
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/Regression/C//callargs.c

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

typedef struct SmallStruct_struct {
  char c1, c2, c3, c4;
  int  n;
} SmallStruct;

typedef struct BigStruct_struct {
  char       c1, c2, c3, c4;
  double     d1, d2;
  int        n;
  struct BigStruct_struct* next;
} BigStruct;

void printArgsNoRet(int a1,  float a2,  char a3,  double a4,  char* a5,
                    int a6,  float a7,  char a8,  double a9,  char* a10,
                    int a11, float a12, char a13, double a14, char* a15) {
  printf("\nprintArgsNoRet with 15 arguments:\n");
  printf("\tArgs 1-5  : %d %f %c %f %c\n", a1,  a2,  a3,  a4,  *a5);
  printf("\tArgs 6-10 : %d %f %c %f %c\n", a6,  a7,  a8,  a9,  *a10);
  printf("\tArgs 11-14: %d %f %c %f %c\n", a11, a12, a13, a14, *a15);
  printf("\n");
}

int main(int argc, char *argv[]) {
  if (argc != 16) {
    printf("Usage: %s <value1> <value2> <value3> ... <value15>\n", argv[0]);
    return 1;
  }

  int a1 = atoi(argv[1]);
  float a2 = atof(argv[2]);
  char a3 = argv[3][0];
  double a4 = atof(argv[4]);
  char *a5 = argv[5];

  int a6 = atoi(argv[6]);
  float a7 = atof(argv[7]);
  char a8 = argv[8][0];
  double a9 = atof(argv[9]);
  char *a10 = argv[10];

  int a11 = atoi(argv[11]);
  float a12 = atof(argv[12]);
  char a13 = argv[13][0];
  double a14 = atof(argv[14]);
  char *a15 = argv[15];

  printArgsNoRet(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15);

  return 0;
}
