// Modification timestamp: 2023-08-14 13:19:55
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20120105-1.c
#include <stdlib.h>

#include <stdio.h>
#include <string.h>

struct __attribute__((packed)) S
{
  int a, b, c;
};

static int __attribute__ ((noinline,noclone))
extract(const char *p, int a_offset)
{
  struct S s;
  memcpy (&s, p, sizeof(struct S));
  return s.a;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int a_offset = atoi(argv[1]);
  char p[sizeof(struct S) + 1];
  memset(p, 0, sizeof(struct S) + 1);
  int i = extract(p + a_offset, a_offset);

  return 0;
}
