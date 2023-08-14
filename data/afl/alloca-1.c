// Modification timestamp: 2023-08-14 14:00:00
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/alloca-1.c

#include <stdio.h>
#include <stdlib.h>

typedef __SIZE_TYPE__ size_t;

struct dummy { int x __attribute__((aligned)); };
#define BIGGEST_ALIGNMENT __alignof__(struct dummy)

_Bool foo(void)
{
  char *p = __builtin_alloca(32);
  return ((size_t)p & (BIGGEST_ALIGNMENT - 1)) == 0;
}

int main(int argc, char *argv[]) {
    if (!foo()) {
        abort();
    }
    return 0;
}
