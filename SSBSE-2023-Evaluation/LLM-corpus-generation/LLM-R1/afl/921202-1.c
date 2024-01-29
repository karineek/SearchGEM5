// Modification timestamp: 2023-08-14 13:32:01
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/921202-1.c

#include <stdio.h>
#include <stdlib.h>

#ifndef STACK_SIZE
#define	VLEN	2055
#else
#define VLEN ((STACK_SIZE/16) - 1)
#endif

void foo(char* arg1, int arg2, int arg3) {}
void mpn_mul_1(long* arg1, long* arg2, long arg3) {}
void mpn_print(long* arg1, long arg2) {}
void mpn_random2(long* arg1, long arg2) {}
int mpn_cmp(long* arg1, long* arg2, long arg3) {}
void exxit() { exit(0); }

int main(int argc, char *argv[]) {
  long dx[VLEN + 1];
  long dy[VLEN + 1];
  long s1[VLEN];
  int cyx, cyy;
  int i;
  long size;

  for (;;) {
    if (argc != 2) {
      printf("Usage: %s <value>\n", argv[0]);
      return 1;
    }

    size = VLEN;
    mpn_random2(s1, size);

    for (i = 0; i < 1; i++)
      ;

    dy[size] = atoi(argv[1]);

    for (i = 0; i < 1; i++)
      cyy = mpn_mul_1(dy, s1, size);

    if (cyx != cyy || mpn_cmp(dx, dy, size + 1) != 0 || dx[size] != atoi(argv[1])) {
      foo("", 8, cyy);
      mpn_print(dy, size);
    }
    exxit();
  }
}
