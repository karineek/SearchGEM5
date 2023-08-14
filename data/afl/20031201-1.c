// Modification timestamp: 2023-08-14 12:50:26
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20031201-1.c

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  unsigned int e0 : 16;
  unsigned int e1 : 16;
} s1;

typedef struct {
  unsigned int e0 : 16;
  unsigned int e1 : 16;
} s2;

typedef struct {
  s1 i12;
  s2 i16;
} io;

static int test_length = 2;
static io *i;
static int m = 1;
static int d = 1;
static unsigned long test_t0;
static unsigned long test_t1;

void test(void) __attribute__ ((__noinline__));
extern int f1(void *port) __attribute__ ((__noinline__));
extern void f0(void) __attribute__ ((__noinline__));

int f1(void *port) {
  int fail_count = 0;
  unsigned long tlen;
  s1 x0 = {0};
  s2 x1 = {0};

  i = port;
  x0.e0 = x1.e0 = atoi(argv[1]);
  i->i12 = x0;
  i->i16 = x1;
  do f0(); while (test_t1);
  x0.e0 = x1.e0 = atoi(argv[2]);
  i->i12 = x0;
  i->i16 = x1;
  test();
  if (m) {
    unsigned long e = 1000000000 / 460800 * test_length;
    tlen = test_t1 - test_t0;
    if (((tlen - e) & 0x7FFFFFFF) > 1000)
      f0();
  }
  if (d) {
    unsigned long e = 1000000000 / 460800 * test_length;
    tlen = test_t1 - test_t0;
    if (((tlen - e) & 0x7FFFFFFF) > 1000)
      f0();
  }
  return fail_count != 0 ? 1 : 0;
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <value1> <value2>\n", argv[0]);
    return 1;
  }
  
  io io0;
  f1(&io0);
  abort();
}

void test(void) {
  io *iop = i;
  if (iop->i12.e0 != atoi(argv[2]) || iop->i16.e0 != atoi(argv[2]))
    abort();
  exit(0);
}

void f0(void) {
  static int washere = 0;
  io *iop = i;
  if (washere++ || iop->i12.e0 != atoi(argv[1]) || iop->i16.e0 != atoi(argv[1]))
    abort();
}
