// Modification timestamp: 2023-08-14 17:17:43
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2005-07-17-INT-To-FP.c
#include <stdlib.h>

#include <stdio.h>

int tests[] = {
  0x80000000,
  -123456792,
  -10,
  -2,
  -1,
  0,
  1,
  2,
  10,
  123456792,
  0x7FFFFF80
};

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }
  
  unsigned i;
  // byte boundary tests
  for (i = 0; i < 64; ++i) {
    printf("%d %f, %f, %f, %f\n", i,
           (double)(signed char)(i << atoi(argv[1])),            // i8
           (double)(signed short)(i << atoi(argv[2])),          // i16
           (double)(signed int)(i << atoi(argv[3])),            // i32
           (double)(signed long long)((long long)i << atoi(argv[4])));  // i64

    printf("%d %f, %f, %f, %f\n", i,
           (double)(unsigned char)(i << atoi(argv[5])),            // i8
           (double)(unsigned short)(i << atoi(argv[6])),          // i16
           (double)(unsigned int)(i << atoi(argv[7])),            // i32
           (double)(unsigned long long)((unsigned long long)i << atoi(argv[8])));  // i64
  }
  // edge case tests
  for (i = 0; i < (sizeof(tests) / sizeof(int)); i++) {
    printf("%d %f, %f, %f, %f\n", i,
                               (double)(unsigned)tests[i],
                               (double)(  signed)tests[i],
                               (float)           tests[i],
                               (float) (  signed)tests[i]);
  }
  return 0;
}


// Compile and run the program with command-line arguments to provide the values for `atoi(argv[X])` where `X` ranges from 1 to 8.
