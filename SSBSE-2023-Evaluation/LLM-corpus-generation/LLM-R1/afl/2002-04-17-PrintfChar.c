// Modification timestamp: 2023-08-14 17:10:16
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2002-04-17-PrintfChar.c

#include <stdio.h>

int printf(const char*, ...);

void printArgsNoRet(char a3, char* a5) {
  printf("'%c' '%c'\n", (int)a3, (int)*a5);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  printArgsNoRet(argv[1][0], argv[2]);
  return 0;
}
