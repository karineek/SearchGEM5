// Modification timestamp: 2023-08-02 15:30:00
// Original Source: https://github.com/llvm/llvm-test-suite/blob/master/MultiSource/Benchmarks/MallocBench/espresso/20000112-1.c

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static int
special_format (fmt)
     const char *fmt;
{
  return (strchr (fmt, '*') != 0
          || strchr (fmt, 'V') != 0
          || strchr (fmt, 'S') != 0
          || strchr (fmt, 'n') != 0);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <fmt>\n", argv[0]);
        return 1;
    }

    const char *fmt = argv[1];
    if (special_format(fmt))
        abort();
    if (!special_format("*e"))
        abort();
    exit(0);
}
