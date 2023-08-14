// Modification timestamp: 2023-08-14 13:31:30
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/921117-1.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s {
  char text[11];
  int flag;
} cell;

int check(struct s p, char* arg1, char* arg2) {
  if (p.flag != atoi(arg1))
    return 1;
  return strcmp(p.text, arg2);
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <flag> <text>\n", argv[0]);
    return 1;
  }

  cell.flag = atoi(argv[1]);
  strcpy(cell.text, argv[2]);

  if (check(cell, argv[1], argv[2]))
    abort();
  exit(0);
}
