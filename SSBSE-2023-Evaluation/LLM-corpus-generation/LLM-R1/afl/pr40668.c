// Modification timestamp: 2023-08-14 15:06:57
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr40668.c

#include <stdio.h>
#include <stdlib.h>

#if (__SIZEOF_INT__ == 2)
#define TESTVALUE 0x1234
#else
#define TESTVALUE 0x12345678
#endif

static void foo(unsigned int x, void *p) {
  __builtin_memcpy(p, &x, sizeof x);
}

void bar(int type, void *number) {
  switch (type) {
    case 1:
      foo(TESTVALUE, number);
      break;
    case 7:
      foo(0, number);
      break;
    case 8:
      foo(0, number);
      break;
    case 9:
      foo(0, number);
      break;
  }
}

int main(void) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }
  
  unsigned int x;
  int type = atoi(argv[1]);
  bar(type, &x);
  if (x != TESTVALUE) {
    printf("x != TESTVALUE\n");
    return 1;
  }
  
  return 0;
}
