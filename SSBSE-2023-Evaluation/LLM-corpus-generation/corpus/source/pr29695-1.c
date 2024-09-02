// Modification timestamp: 2023-08-14 14:52:26
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr29695-1.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

int f1(int a) {
  return (a & 0x80) ? 0x80 : 0;
}

int f2(unsigned char a) {
  return (a & 0x80) ? 0x80 : 0;
}

int f3(unsigned char a) {
  return (a & 0x80) ? 0x380 : 0;
}

int f4(unsigned char a) {
  return (a & 0x80) ? -128 : 0;
}

long long f5(long long a) {
  return (a & 0x80000000) ? 0x80000000LL : 0LL;
}

long long f6(unsigned int a) {
  return (a & 0x80000000) ? 0x80000000LL : 0LL;
}

long long f7(unsigned int a) {
  return (a & 0x80000000) ? 0x380000000LL : 0LL;
}

long long f8(unsigned int a) {
  return (a & 0x80000000) ? -2147483648LL : 0LL;
}

int main(int argc, char *argv[]) {
  if ((char)128 != -128 || (int)0x80000000 != -2147483648)
    return 0;
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }
  int a = atoi(argv[1]);
  if (f1(a) != 128)
    abort();
  if (f2(a) != 128)
    abort();
  if (f3(a) != 896)
    abort();
  if (f4(a) != -128)
    abort();
  if (f5(a) != 0x80000000LL)
    abort();
  if (f6(a) != 0x80000000LL)
    abort();
  if (f7(a) != 0x380000000LL)
    abort();
  if (f8(a) != -2147483648LL)
    abort();
  return 0;
}
