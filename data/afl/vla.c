c
// Modification timestamp: 2023-08-10 15:51:01
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/MultiSource/Benchmarks/MallocBench/espresso/espresso.c

#include <stdio.h>
#include <stdlib.h>

extern void abort();

int bork[4][3] = { 1,2,3,4,5,6,7,8,9,10,11,12};
void function(short width, int data[][width]) {
  int i,j;
  for (i = 0; i < 4; i++)
    for (j = 0; j < width; j++)
      if (bork[i][j] != data[i][j])
        abort();
}


void test() {
     function(3, bork);
}

int bork2[2][3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12, 13,14,15,16,17,18,19,20,21,22,23,24};
void function2(short width, short width2, int data[][width][width2]) {
  int i,j,k;
  for (i = 0; i < 2; i++)
    for (j = 0; j < width; j++)
      for (k = 0; k < width2; k++)
        if (bork2[i][j][k] != data[i][j][k])
          abort();
}


void test2() {
     function2(3, 4, bork2);
}
int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  unsigned int seed = atoi(argv[1]);
  srand(seed);

  test();
  test2();
  return 0;
}
