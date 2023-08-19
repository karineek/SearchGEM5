// Modification timestamp: 2023-08-14 12:47:54
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20030811-1.c
/* Origin: PR target/11535 from H. J. Lu <hjl@lucon.org> */
/* { dg-require-effective-target return_address } */

#include <stdio.h>

void vararg (int i, ...)
{
  (void) i;
}

void test1 (void)
{
  int a = atoi(argv[1]);
  vararg (0, a);
}

void test2 (void)
{
  i0[0] = atoi(argv[1]);
}

void test3 (void)
{
  i1 = atoi(argv[1]);
}

void test4 (void)
{
  volatile long long a = atoi(argv[1]);
  i0[0] = (int) a;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  return 0;
}