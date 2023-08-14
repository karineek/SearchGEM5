// Modification timestamp: 2023-08-14 17:28:38
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/ms_struct-bitfield-init-1.c

#include <stdlib.h>

#define ATTR __attribute__((__ms_struct__))

// GCC only implements #pragma ms_struct on Darwin.
#define HAVE_PRAGMA_MS_STRUCT (defined(__clang__) || defined(__MACH__))

struct {
  unsigned int bf_1;
  unsigned int : 0;
  unsigned int bf_2;
} ATTR t1;
static int a1[(sizeof(t1) == 8) - 1];

struct {
  char foo;
  short;
  char bar;
} ATTR t2;
static int a2[(sizeof(t2) == 4) - 1];

#if HAVE_PRAGMA_MS_STRUCT
#pragma ms_struct on
struct {
  char foo;
  short;
  char bar;
} t3;
#pragma ms_struct off
static int a3[(sizeof(t3) == 4) - 1];
#endif

struct {
  char foo;
  int;
} ATTR t4;
static int a4[(sizeof(t4) == 4) - 1];

struct {
  char foo;
  short;
  char bar;
} ATTR t5;
static int a5[(sizeof(t5) == 4) - 1];

struct {
  char foo;
  short;
  long;
  char bar;
} ATTR t6;
static int a6[(sizeof(t6) == 4) - 1];

struct {
  char foo;
  int;
  short;
  char bar;
} ATTR t7;
static int a7[(sizeof(t7) == 8) - 1];

struct {
  char foo;
  short;
  int;
  char bar: 7;
} ATTR t8;
static int a8[(sizeof(t8) == 4) - 1];

struct {
  char foo;
  char;
  short;
  int;
  long;
  char bar;
} ATTR t10;
static int a10[(sizeof(t10) == 2) - 1];

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  t1.bf_1 = atoi(argv[1]);
  t1.bf_2 = atoi(argv[2]);

  t2.foo = atoi(argv[3]);
  t2.bar = atoi(argv[4]);

#if HAVE_PRAGMA_MS_STRUCT
  t3.foo = atoi(argv[5]);
  t3.bar = atoi(argv[6]);
#endif

  t5.foo = atoi(argv[7]);
  t5.bar = atoi(argv[8]);

  t6.foo = atoi(argv[9]);
  t6.bar = atoi(argv[10]);

  t7.foo = atoi(argv[11]);
  t7.bar = atoi(argv[12]);

  t8.foo = atoi(argv[13]);
  t8.bar = atoi(argv[14]);

  t10.foo = atoi(argv[15]);
  t10.bar = atoi(argv[16]);

  if (t1.bf_1 != 1 || t1.bf_2 != 2)
    abort();
  if (t2.foo != 3 || t2.bar != 4)
    abort();
#if HAVE_PRAGMA_MS_STRUCT
  if (t3.foo != 5 || t3.bar != 6)
    abort();
#endif
  if (t5.foo != 7 || t5.bar != 8)
    abort();
  if (t6.foo != 5 || t6.bar != 10)
    abort();
  if (t7.foo != 5 || t7.bar != 10)
    abort();
  if (t8.foo != 5 || t8.bar != 10)
    abort();
  if (t10.foo != 5 || t10.bar != 10)
    abort();

  return 0;
}
