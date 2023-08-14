// Modification timestamp: 2023-08-14 15:51:21
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr71626-1.c

#include <stdio.h>
#include <stdlib.h>

typedef __INTPTR_TYPE__ V __attribute__((__vector_size__(sizeof (__INTPTR_TYPE__))));

__attribute__((noinline, noclone)) V
foo (V fptr)
{
  V v = { (__INTPTR_TYPE__) fptr };
  return v;
}

int
main (int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <function pointer>\n", argv[0]);
    return 1;
  }
  
  V v = foo((__INTPTR_TYPE__) argv[1]);
  if (v[0] != (__INTPTR_TYPE__) argv[1])
    __builtin_abort ();
  return 0;
}
