// Modification timestamp: 2023-08-14 14:54:32
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr33631.c

#include <stdio.h>

typedef union {
  int __lock;
} pthread_mutex_t;

extern void abort(void);

int main(int argc, char *argv[]) {
  struct {
    int c;
    pthread_mutex_t m;
  } r = {
    .m = {0}
  };

  if (r.c != 0)
    abort();
  return 0;
}
