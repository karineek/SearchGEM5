// Modification timestamp: 2023-08-14 12:06:07
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20011024-1.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char buf[50];

static void foo (char* arg1, const char* arg2, const char* arg3)
{
  if (memcpy(arg1, arg2, strlen(arg2) + 1) != arg1) abort();
  if (strcmp(arg1, arg3)) abort();
  memcpy(arg1, arg3, strlen(arg3) + 1);
}

int main(int argc, char* argv[])
{
  if (argc != 4) {
    printf("Usage: %s <arg1> <arg2> <arg3>\n", argv[0]);
    return 1;
  }

  foo(buf, argv[1], argv[2]);
  return 0;
}
