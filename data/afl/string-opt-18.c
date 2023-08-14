// Modification timestamp: 2023-08-14 16:15:27
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/string-opt-18.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test1(void *ptr)
{
  if (memcpy(ptr,ptr,8) != ptr)
    abort();
}

void test2(char *ptr)
{
  if (mempcpy(ptr,ptr,8) != ptr+8)
    abort();
}

void test3(void *ptr)
{
  if (memmove(ptr,ptr,8) != ptr)
    abort();
}

void test4(char *ptr)
{
  if (strcpy(ptr,ptr) != ptr)
    abort();
}

void test5(void *ptr)
{
  if (memcmp(ptr,ptr,8) != 0)
    abort();
}

void test6(const char *ptr)
{
  if (strcmp(ptr,ptr) != 0)
    abort();
}

void test7(const char *ptr)
{
  if (strncmp(ptr,ptr,8) != 0)
    abort();
}

int main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  char buf[10];
  strcpy(buf, argv[1]);

  test1(buf);
  test2(buf);
  test3(buf);
  test4(buf);
  test5(buf);
  test6(buf);
  test7(buf);

  return 0;
}


This converts the program to accept a string argument from the command line and assigns it to the `buf` array.