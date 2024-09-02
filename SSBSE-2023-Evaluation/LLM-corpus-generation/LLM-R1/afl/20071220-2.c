// Modification timestamp: 2023-08-14 13:13:04
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20071220-2.c

#include <stdio.h>
#include <stdlib.h>

void *__attribute__((noinline))
baz(void **lab)
{
  asm volatile("" : "+r"(lab));
  return *lab;
}

static inline
int bar(void)
{
  static void *b[] = {&&addr};
  baz(b);
addr:
  return 17;
}

int __attribute__((noinline))
f1(void)
{
  return bar();
}

int __attribute__((noinline))
f2(void)
{
  return bar();
}

int main(int argc, char *argv[])
{
  if (f1() != 17 || f1() != 17 || f2() != 17 || f2() != 17)
    abort();
  return 0;
}
