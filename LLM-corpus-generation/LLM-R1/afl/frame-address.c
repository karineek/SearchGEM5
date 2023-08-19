// Modification timestamp: 2023-08-14 14:27:44
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/frame-address.c

#include <stdio.h>
#include <stdlib.h>

int check_fa_work(const char *, const char *) __attribute__((noinline));
int check_fa_mid(const char *) __attribute__((noinline));
int check_fa(char *) __attribute__((noinline));
int how_much(void) __attribute__((noinline));

int check_fa_work(const char *c, const char *f) {
  const char d = 0;

  if (c >= &d)
    return c >= f && f >= &d;
  else
    return c <= f && f <= &d;
}

int check_fa_mid(const char *c) {
  const char *f = __builtin_frame_address(0);

  /* Prevent a tail call to check_fa_work, eliding the current stack frame.  */
  return check_fa_work(c, f) != 0;
}

int check_fa(char *unused) {
  const char c = 0;

  /* Prevent a tail call to check_fa_mid, eliding the current stack frame.  */
  return check_fa_mid(&c) != 0;
}

int how_much(void) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int x = atoi(argv[1]);
  int y = atoi(argv[2]);
  return x - y;
}

int main(void) {
  char *unused = __builtin_alloca(how_much());

  if (!check_fa(unused))
    abort();
  return 0;
}
