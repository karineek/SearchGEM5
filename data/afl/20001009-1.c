// Modification timestamp: 2023-08-14 11:52:16
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20001009-1.c

#include <stdio.h>
#include <stdlib.h>

int a, b;

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <a_value> <b_value>\n", argv[0]);
    return 1;
  }

  a = atoi(argv[1]);
  b = atoi(argv[2]);

  int c = -2;
  int d = 0xfe;
  int e = a & 1;
  int f = b & 2;
  
  if ((char)(c | (e & f)) == (char)d)
    return 0;
  else
    abort();
}
