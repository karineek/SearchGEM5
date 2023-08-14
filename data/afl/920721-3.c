// Modification timestamp: 2023-08-14 13:28:49
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/920721-3.c

#include <stdio.h>
#include <stdlib.h>

static inline int fu(unsigned short data) {
  return data;
}

void ru(int i) {
  if (fu(i++) != 5)
    abort();
  if (fu(++i) != 7)
    abort();
}

static inline int fs(signed short data) {
  return data;
}

void rs(int i) {
  if (fs(i++) != 5)
    abort();
  if (fs(++i) != 7)
    abort();
}

int main(int argc, char *argv[]) {
  ru(atoi(argv[1]));
  rs(atoi(argv[2]));
  exit(0);
}

Note: The program assumes that command-line arguments `argv[1]` and `argv[2]` will be passed.