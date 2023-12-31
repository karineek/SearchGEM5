// Modification timestamp: 2023-08-14 17:35:31
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/Regression/C//float16-smoke.c

#include <stdio.h>
#include <stdlib.h>

#ifdef __FLT16_DIG__

typedef _Float16 fp16_t;
__attribute__((noinline))
void printArg(fp16_t a0) {
  printf("printArg: %a\n", (double)a0);
}

fp16_t g_fp16 = 1.0;

int main(int argc, char** argv) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  fp16_t arg0 = (__FLT16_DIG__)atof(argv[1]);
  printArg(arg0);
  printArg((__FLT16_DIG__)0x1p0);
  printArg((__FLT16_DIG__)-0x1p-8);
  printArg(g_fp16 + (__FLT16_DIG__)0x1p0);

  return 0;
}

#else

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  printf("printArg: 0x0p+0\n");
  printf("printArg: 0x1p+0\n");
  printf("printArg: -0x1p-8\n");
  printf("printArg: 0x1p+1\n");
  return 0;
}

#endif
