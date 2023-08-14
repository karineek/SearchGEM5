// Modification timestamp: 2023-08-14 11:55:55
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20010116-1.c

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int x, y, z;
} Data;

extern void ok(int i);

void find(Data *first, Data *last) {
  int i;
  for (i = (last - first) >> 2; i > 0; --i)
    ok(i);
  abort();
}

void ok(int i) {
  if (i != 1)
    abort();
  exit(0);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int x = atoi(argv[1]);

  Data DataList[4];
  find(DataList + x, DataList + 4);
}
