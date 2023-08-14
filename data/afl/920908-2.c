// Modification timestamp: 2023-08-14 13:30:03
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/920908-2.c

#include <stdio.h>
#include <stdlib.h>

#if __INT_MAX__ < 2147483647
int main(void) {
  exit(0);
}
#else
struct T {
  unsigned i:8;
  unsigned c:24;
};

int f(struct T t) {
  struct T s[1];
  s[0] = t;
  return (char)s->c;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  struct T t;
  t.i = 0xff;
  t.c = atoi(argv[1]);
  if (f(t) != atoi(argv[2])) {
    abort();
  }
  exit(0);
}
#endif
