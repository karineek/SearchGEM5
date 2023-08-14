// Modification timestamp: 2023-08-14 13:31:24
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/921113-1.c

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  float wsx;
} struct_list;

typedef struct_list *list_t;

typedef struct {
  float x, y;
} vector_t;

void w(float x, float y) {}

void f1(float x, float y) {
  if (x != 0 || y != 0)
    abort();
}

void f2(float x, float y) {
  if (x != 1 || y != 1)
    abort();
}

void gitter(int count, vector_t pos[], list_t list, int *nww, vector_t limit[2], float r) {
  float d;
  int gitt[128][128];

  f1(limit[0].x, limit[0].y);
  f2(limit[1].x, limit[1].y);

  *nww = 0;

  d = pos[0].x;
  if (d <= 0.) {
    w(d, r);
    if (d <= r * 0.5) {
      w(d, r);
      list[0].wsx = 1;
    }
  }
}

vector_t pos[1] = {{0., 0.}};
vector_t limit[2] = {{0.,0.},{1.,1.}};

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int nww;
  struct_list list;

  gitter(1, pos, &list, &nww, limit, atof(argv[1]));
  exit(0);
}
