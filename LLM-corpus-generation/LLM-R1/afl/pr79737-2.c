// Modification timestamp: 2023-08-14 15:54:48
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr79737-2.c

#include <stdio.h>
#include <stdlib.h>

#if __SIZEOF_INT__ < 4
  __extension__ typedef __INT32_TYPE__ int32_t;
#else
  typedef int int32_t;
#endif

#pragma pack(1)
struct S
{
  int32_t b:18;
  int32_t c:1;
  int32_t d:24;
  int32_t e:15;
  int32_t f:14;
} i, j;

void foo(int32_t arg1, int32_t arg2, int32_t arg3, int32_t arg4, int32_t arg5)
{
  i.e = arg1;
  i.b = arg2;
  i.c = arg3;
  i.d = arg4;
  i.f = arg5;
}

void bar(int32_t arg1, int32_t arg2, int32_t arg3, int32_t arg4, int32_t arg5)
{
  j.b = arg1;
  j.c = arg2;
  j.d = arg3;
  j.e = arg4;
  j.f = arg5;
}

int main(int argc, char *argv[])
{
  if (argc != 7) {
    printf("Usage: %s <arg1> <arg2> <arg3> <arg4> <arg5> <arg6>\n", argv[0]);
    return 1;
  }

  int32_t arg1 = atoi(argv[1]);
  int32_t arg2 = atoi(argv[2]);
  int32_t arg3 = atoi(argv[3]);
  int32_t arg4 = atoi(argv[4]);
  int32_t arg5 = atoi(argv[5]);
  int32_t arg6 = atoi(argv[6]);

  foo(arg1, arg2, arg3, arg4, arg5);
  bar(arg2, arg3, arg4, arg5, arg6);

  asm volatile ("" : : : "memory");
  if (i.b != j.b || i.c != j.c || i.d != j.d || i.e != j.e || i.f != j.f)
    __builtin_abort ();

  return 0;
}
