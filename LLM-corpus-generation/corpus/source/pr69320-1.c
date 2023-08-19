// Modification timestamp: 2023-08-14 15:48:31
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr69320-1.c

#include <stdlib.h>

int a, b, d, f;
char c;
static int *e = &d;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int g = atoi(argv[1]);
  *e = g;
  c = atoi(argv[2]);
  for (; c >= atoi(argv[3]); c++)
    *e = atoi(argv[4]);
  f = a == atoi(argv[5]);
  *e ^= f;
  int h = ~d;
  if (d)
    b = h;
  if (h)
    exit(0);
  abort();
}


//Please replace `<value>` and `<argc>` with the appropriate values when running the program.