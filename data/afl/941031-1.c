// Modification timestamp: 2023-08-14 13:40:59
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/941031-1.c

#include <stdio.h>
#include <stdlib.h>

typedef long mpt;

int f(mpt us, mpt vs) {
  long aus;
  long avs;

  aus = us >= 0 ? us : -us;
  avs = vs >= 0 ? vs : -vs;

  if (aus < avs) {
    long t = aus;
    aus = avs;
    avs = aus;
  }

  return avs;
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <value1> <value2>\n", argv[0]);
    return 1;
  }

  mpt arg1 = (mpt)atoi(argv[1]);
  mpt arg2 = (mpt)atoi(argv[2]);

  if (f(arg1, arg2) != (mpt)17)
    abort();

  exit(0);
}
