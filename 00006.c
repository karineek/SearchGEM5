// Modification timestamp: 2023-08-02 17:25:00
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00006.c

int main() {
  int x;

  x = 50;
  while (x)
    x = x - 1;
  return x;
}
