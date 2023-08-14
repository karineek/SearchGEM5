
// Modification timestamp: 2023-08-02 17:40:00
// Original Source: https://github.com/llvm/llvm-test-suite/blob/master/MultiSource/Benchmarks/MallocBench/espresso/20000112-1.c

#include <string.h>

static int
special_format (fmt)
     const char *fmt;
{
  return (strchr (fmt, '*') != 0
          || strchr (fmt, 'V') != 0
          || strchr (fmt, 'S') != 0
          || strchr (fmt, 'n') != 0);
}

int main() {
    if (special_format ("ee"))
        abort();
    if (!special_format ("*e"))
        abort();
    exit(0);
}
