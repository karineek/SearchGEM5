// Modification timestamp: 2023-08-14 15:49:41
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr70005.c

#include <stdio.h>

unsigned char a = 6;
int b, c;

static void fn1(int argc, char *argv[]) {
  int i = atoi(argv[1]) > 1 ? 1 : atoi(argv[1]), j = 6 & (c = atoi(argv[1]) && (b = atoi(argv[1])));
  int d = 0, e = atoi(argv[1]), f = ~c, g = b || atoi(argv[1]);
  unsigned char h = ~atoi(argv[1]);
  if (atoi(argv[1]))
    f = j;
  if (h && g)
    d = atoi(argv[1]);
  i = -~(f * d * h) + c && (e || i) ^ f;
  if (i != 1)
    __builtin_abort();
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  fn1(argc, argv);
  return 0;
}
