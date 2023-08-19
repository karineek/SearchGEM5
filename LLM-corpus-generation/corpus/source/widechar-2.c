// Modification timestamp: 2023-08-14 17:04:40
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/widechar-2.c

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  const wchar_t ws[] = {argv[1][0], argv[1][1], argv[1][2], L'\0'};

  if (ws[0] != L'f' || ws[1] != L'o' || ws[2] != L'o' || ws[3] != L'\0')
    abort();
  
  exit(0);
}
