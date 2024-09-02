// Modification timestamp: 2023-08-14 13:34:13
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/930603-3.c

#include <stdio.h>
#include <stdlib.h>

unsigned long my_function(unsigned char *b, int c) {
  unsigned long v = 0;
  switch (c) {
    case 'd':
      v = ((unsigned long)b[0] << 8) + b[1];
      v >>= 9;
      break;
    case 'k':
      v = b[3] >> 4;
      break;
    default:
      abort();
  }
  return v;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }
  
  char buf[4];
  buf[0] = atoi(argv[1]);
  buf[1] = atoi(argv[2]);

  if (my_function(buf, 'd') != 85) {
    abort();
  }
  
  exit(0);
}
