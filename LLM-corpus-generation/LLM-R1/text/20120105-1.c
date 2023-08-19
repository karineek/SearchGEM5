// Modification timestamp: 2023-08-14 13:19:55
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20120105-1.c
struct __attribute__((packed)) S
{
  int a, b, c;
};

static int __attribute__ ((noinline,noclone))
extract(const char *p)
{
  struct S s;
  __builtin_memcpy (&s, p, sizeof(struct S));
  return s.a;
}

volatile int i;

int main (void)
{
  char p[sizeof(struct S) + 1];

  __builtin_memset (p, 0, sizeof(struct S) + 1);
  i = extract (p + 1);

  return 0;
}
