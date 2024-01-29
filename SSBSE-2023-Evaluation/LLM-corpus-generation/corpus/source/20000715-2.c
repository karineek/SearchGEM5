
// Modification timestamp: 2023-08-10 16:39:16
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20000715-2.c
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

extern void abort(void);
extern void exit(int);

unsigned int foo(unsigned int a)
{
  return ((unsigned char)(a + 1)) * 4;
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
      printf("Usage: %s <value>\n", argv[0]);
      return 1;
    }

    unsigned int arg = atoi(argv[1]);
    if (foo((unsigned char)arg))
      abort ();
    exit(0);
}
