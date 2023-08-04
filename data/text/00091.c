
// Modification timestamp: 2023-08-04 14:09:15
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00091.c

typedef struct {
  int v;
  int sub[2];
} S;

S a[1] = {{1, {2, 3}}};

int main() {
  if (a[0].v != 1)
    return 1;
  if (a[0].sub[0] != 2)
    return 2;
  if (a[0].sub[1] != 3)
    return 3;

  return 0;
}
