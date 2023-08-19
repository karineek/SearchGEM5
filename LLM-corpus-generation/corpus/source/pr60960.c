// Modification timestamp: 2023-08-14 15:38:03
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr60960.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char v4qi __attribute__ ((vector_size (4)));

__attribute__((noinline, noclone)) v4qi
f1(v4qi v, v4qi d)
{
  return v / d;
}

__attribute__((noinline, noclone)) v4qi
f2(v4qi v, v4qi d)
{
  return v / d;
}

__attribute__((noinline, noclone)) v4qi
f3(v4qi x, v4qi y, v4qi d)
{
  return x / y;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  v4qi x = {atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4])};
  v4qi y = {atoi(argv[5]), atoi(argv[6]), atoi(argv[7]), atoi(argv[8])};
  v4qi z = f1(x, (v4qi) {2, 2, 2, 2});
  if (__builtin_memcmp(&y, &z, sizeof(y)) != 0)
    __builtin_abort();
  z = f2(x, (v4qi) {2, 2, 2, 2});
  if (__builtin_memcmp(&y, &z, sizeof(y)) != 0)
    __builtin_abort();
  z = f3(x, y, (v4qi) {2, 2, 2, 2});
  if (__builtin_memcmp(&y, &z, sizeof(y)) != 0)
    __builtin_abort();
  return 0;
}
