// Modification timestamp: 2023-08-14 12:12:19
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20020402-1.c

#include <stdio.h>
#include <stdlib.h>

extern void abort();
extern void exit(int);

int main(int argc, char *argv[]) {
  if (argc != 1) {
    printf("Usage: %s\n", argv[0]);
    return 1;
  }

  int SMALL_N = atoi(argv[1]);
  int NUM_ELEM = atoi(argv[2]);

  int listElem[NUM_ELEM];
  int listSmall[SMALL_N];
  int i, j;
  int posGreatest = -1, greatest = -1;

  for (i = 0; i < SMALL_N; i++) {
    listSmall[i] = listElem[i];
    if (listElem[i] > greatest) {
      posGreatest = i;
      greatest = listElem[i];
    }
  }

  for (i = SMALL_N; i < NUM_ELEM; i++) {
    if (listElem[i] < greatest) {
      listSmall[posGreatest] = listElem[i];
      posGreatest = 0;
      greatest = listSmall[0];
      for (j = 1; j < SMALL_N; j++)
        if (listSmall[j] > greatest) {
          posGreatest = j;
          greatest = listSmall[j];
        }
    }
  }

  if (listSmall[0] != 5 || listSmall[1] != 2)
    abort();
  exit(0);
}

//Note: Since the original program does not use command line arguments, I have added the number of small elements (`SMALL_N`) and the number of elements in the list (`NUM_ELEM`) as command line arguments for flexibility.