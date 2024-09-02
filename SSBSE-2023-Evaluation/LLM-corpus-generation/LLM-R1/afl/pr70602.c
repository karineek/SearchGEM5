// Modification timestamp: 2023-08-14 15:50:38
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr70602.c

#include <stdio.h>

struct __attribute__((packed)) S
{
  int s : 1;
  int t : 20;
};

int main(int argc, char *argv[]) {
  int a, b, c;

  for (; a < 1; a++)
  {
    struct S e[] = { {0, 9}, {0, 9}, {0, 9}, {0, 0}, {0, 9}, {0, 9}, {0, 9},
                     {0, 0}, {0, 9}, {0, 9}, {0, 9}, {0, 0}, {0, 9}, {0, 9},
                     {0, 9}, {0, 0}, {0, 9}, {0, 9}, {0, 9}, {0, 0}, {0, 9} };
    b = b || e[0].s;
    c = e[0].t;
  }
  return 0;
}
