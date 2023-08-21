// Modification timestamp: 2023-08-14 13:05:13
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20051104-1.c
#include <stdlib.h>

#include <stdio.h>

struct
{
  int len;
  char *name;
} s;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  s.len = atoi(argv[1]);
  s.name = argv[2];
  if (s.name[s.len] != 0)
    s.name[s.len] = 0;
  return 0;
}
