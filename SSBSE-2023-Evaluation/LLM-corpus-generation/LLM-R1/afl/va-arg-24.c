// Modification timestamp: 2023-08-14 17:00:05
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/va-arg-24.c

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

static int errors = 0;

static void verify(const char* tcase, int n[11]) {
  int i;
  for (i = 0; i <= 10; i++)
    if (n[i] != i) {
      printf(" %s: n[%d] = %d expected %d\n", tcase, i, n[i], i);
      errors++;
    }
}

#define STR(x) #x

#define p(i) int q##i,
#define P(i) n[i] = q##i;

#define p0 p(0)
#define p1 p(1)
#define p2 p(2)
#define p3 p(3)
#define p4 p(4)
#define p5 p(5)
#define p6 p(6)
#define p7 p(7)
#define p8 p(8)
#define p9 p(9)

#define P0 P(0)
#define P1 P(1)
#define P2 P(2)
#define P3 P(3)
#define P4 P(4)
#define P5 P(5)
#define P6 P(6)
#define P7 P(7)
#define P8 P(8)
#define P9 P(9)

#define TCASE(x, params, vecinit) \
  static void varargs##x(params ...) { \
    va_list ap; \
    int n[11]; \
    int i; \
    va_start(ap, q##x); \
    vecinit for (i = x + 1; i <= 10; i++) n[i] = va_arg(ap, int); \
    va_end(ap); \
    verify(STR(varargs##x), n); \
  }

#define TEST(x) varargs##x(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10)

TCASE(0, p0              , P0            )
TCASE(1, p0 p1           , P0 P1         )
TCASE(2, p0 p1 p2        , P0 P1 P2      )
TCASE(3, p0 p1 p2 p3     , P0 P1 P2 P3   )
TCASE(4, p0 p1 p2 p3 p4  , P0 P1 P2 P3 P4)
TCASE(5, p0 p1 p2 p3 p4 p5, P0 P1 P2 P3 P4 P5)

int main(int argc, char* argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int x = atoi(argv[1]);
  int q6 = x;
  int q7 = x;
  int q8 = x;
  int q9 = x;
  int q10 = x;

  TEST(0);
  TEST(1);
  TEST(2);
  TEST(3);
  TEST(4);
  TEST(5);

  if (errors)
    abort();
  return 0;
}
