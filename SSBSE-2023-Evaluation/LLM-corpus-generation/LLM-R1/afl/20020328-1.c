// Modification timestamp: 2023-08-14 12:12:03
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20020328-1.c

#include <stdio.h>
#include <stdlib.h>

int b = 0;

void func() { }

void testit(int x)
{
  if (x != 20)
    abort();
}

int main(int argc, char *argv[])
{
  if (argc != 3) {
    printf("Usage: %s <value1> <value2>\n", argv[0]);
    return 1;
  }

  int a = atoi(argv[1]);
  int b = atoi(argv[2]);

  if (b)
    func();

  /* simplify_and_const_int would incorrectly omit the mask in
     the line below.  */
  testit((a + 23) & 0xfffffffc);
  exit(0);
}

