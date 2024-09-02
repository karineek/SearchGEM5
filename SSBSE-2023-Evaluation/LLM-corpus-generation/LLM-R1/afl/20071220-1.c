// Modification timestamp: 2023-08-14 13:12:57
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20071220-1.c

extern void abort(void);

void *__attribute__((noinline))
baz(void **lab)
{
  asm volatile("" : "+r"(lab));
  return *lab;
}

static inline int bar(void)
{
  static void *b[] = { &&addr };
  void *p = baz(b);
  goto *p;
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
  if (argc != 2)
  {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int x = atoi(argv[1]);
  if (f1() != x || f1() != x || f2() != x || f2() != x)
    abort();
  return 0;
}
