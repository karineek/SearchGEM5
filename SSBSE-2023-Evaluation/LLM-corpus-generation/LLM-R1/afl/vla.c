// Modification timestamp: 2023-08-14 17:31:29
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/vla.c

#include <stdio.h>
#include <stdlib.h>

extern void abort();

int bork[4][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };

void function(short width, int data[][width]) {
  int i, j;
  for (i = 0; i < 4; i++)
    for (j = 0; j < width; j++)
      if (bork[i][j] != data[i][j])
        abort();
}

void test() {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int bork[4][3] = { atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]), atoi(argv[5]), atoi(argv[6]), atoi(argv[7]), atoi(argv[8]), atoi(argv[9]), atoi(argv[10]), atoi(argv[11]), atoi(argv[12]) };
  int data[4][3] = { bork[0][0], bork[0][1], bork[0][2], bork[1][0], bork[1][1], bork[1][2], bork[2][0], bork[2][1], bork[2][2], bork[3][0], bork[3][1], bork[3][2] };

  function(3, data);
}

int bork2[2][3][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24 };

void function2(short width, short width2, int data[][width][width2]) {
  int i, j, k;
  for (i = 0; i < 2; i++)
    for (j = 0; j < width; j++)
      for (k = 0; k < width2; k++)
        if (bork2[i][j][k] != data[i][j][k])
          abort();
}

void test2() {
  if (argc != 4) {
    printf("Usage: %s <value1> <value2> <value3> <value4> <value5> <value6> <value7> <value8> <value9> <value10> <value11> <value12> <value13> <value14> <value15> <value16> <value17> <value18> <value19> <value20> <value21> <value22> <value23> <value24>\n", argv[0]);
    return 1;
  }

  int bork2[2][3][4] = { { { atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]) }, { atoi(argv[5]), atoi(argv[6]), atoi(argv[7]), atoi(argv[8]) }, { atoi(argv[9]), atoi(argv[10]), atoi(argv[11]), atoi(argv[12]) } }, { { atoi(argv[13]), atoi(argv[14]), atoi(argv[15]), atoi(argv[16]) }, { atoi(argv[17]), atoi(argv[18]), atoi(argv[19]), atoi(argv[20]) }, { atoi(argv[21]), atoi(argv[22]), atoi(argv[23]), atoi(argv[24]) } } };
  int data[2][3][4] = { { { bork2[0][0][0], bork2[0][0][1], bork2[0][0][2], bork2[0][0][3] }, { bork2[0][1][0], bork2[0][1][1], bork2[0][1][2], bork2[0][1][3] }, { bork2[0][2][0], bork2[0][2][1], bork2[0][2][2], bork2[0][2][3] } }, { { bork2[1][0][0], bork2[1][0][1], bork2[1][0][2], bork2[1][0][3] }, { bork2[1][1][0], bork2[1][1][1], bork2[1][1][2], bork2[1][1][3] }, { bork2[1][2][0], bork2[1][2][1], bork2[1][2][2], bork2[1][2][3] } } };

  function2(3, 4, data);
}

int main(int argc, char *argv[]) {
  test();
  test2();
  return 0;
}
