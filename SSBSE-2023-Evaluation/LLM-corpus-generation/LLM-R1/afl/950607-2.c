// Modification timestamp: 2023-08-14 13:42:15
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/950607-2.c

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  long int p_x, p_y;
} Point;

int f(Point basePt, Point pt1, Point pt2) {
  long long vector;

  vector = (long long)(pt1.p_x - basePt.p_x) * (long long)(pt2.p_y - basePt.p_y) -
           (long long)(pt1.p_y - basePt.p_y) * (long long)(pt2.p_x - basePt.p_x);

  if (vector > (long long)0)
    return 0;
  else if (vector < (long long)0)
    return 1;
  else
    return 2;
}

int main(int argc, char *argv[]) {
  Point b, p1, p2;
  int answer;

  if (argc != 8) {
    printf("Usage: %s <b.p_x> <b.p_y> <p1.p_x> <p1.p_y> <p2.p_x> <p2.p_y> <expected_answer>\n", argv[0]);
    return 1;
  }

  b.p_x = atol(argv[1]);
  b.p_y = atol(argv[2]);
  p1.p_x = atol(argv[3]);
  p1.p_y = atol(argv[4]);
  p2.p_x = atol(argv[5]);
  p2.p_y = atol(argv[6]);
  answer = f(b, p1, p2);

  int expected_answer = atoi(argv[7]);
  if (answer != expected_answer) {
    abort();
  }
  return 0;
}

