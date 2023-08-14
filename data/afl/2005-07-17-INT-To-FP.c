c
// Modification timestamp: 2023-08-10 15:11:46
// Original Source: https://github.com/llvm/llvm-test-suite

#include <stdio.h>
#include <stdlib.h>

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
           (double)(signed short)(i << atoi(argv[1])),          // i16
           (double)(signed int)(i << atoi(argv[1])),            // i32
           (double)(signed long long)((long long)i << atoi(argv[1])));  // i64

    printf("%d %f, %f, %f, %f\n", i,
           (double)(unsigned char)(i << atoi(argv[1])),            // i8
           (double)(unsigned short)(i << atoi(argv[1])),          // i16
           (double)(unsigned int)(i << atoi(argv[1])),            // i32
           (double)(unsigned long long)((unsigned long long)i << atoi(argv[1])));  // i64
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
