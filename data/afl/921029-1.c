// Modification timestamp: 2023-08-14 13:30:58
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/921029-1.c

#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ULL;
ULL back;
ULL hpart, lpart;

ULL build(ULL h, ULL l) {
  hpart = h;
  hpart <<= 32;
  lpart = l;
  lpart &= 0xFFFFFFFFLL;
  back = hpart | lpart;
  return back;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  if (build(0, 1) != atoll(argv[1])) abort();
  if (build(0, 0) != atoll(argv[2])) abort();
  if (build(0, 0xFFFFFFFF) != atoll(argv[3])) abort();
  if (build(0, 0xFFFFFFFE) != atoll(argv[4])) abort();
  if (build(1, 1) != atoll(argv[5])) abort();
  if (build(1, 0) != atoll(argv[6])) abort();
  if (build(1, 0xFFFFFFFF) != atoll(argv[7])) abort();
  if (build(1, 0xFFFFFFFE) != atoll(argv[8])) abort();
  if (build(0xFFFFFFFF, 1) != atoll(argv[9])) abort();
  if (build(0xFFFFFFFF, 0) != atoll(argv[10])) abort();
  if (build(0xFFFFFFFF, 0xFFFFFFFF) != atoll(argv[11])) abort();
  if (build(0xFFFFFFFF, 0xFFFFFFFE) != atoll(argv[12])) abort();

  exit(0);
}
