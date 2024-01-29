// Modification timestamp: 2023-08-14 13:58:54
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/alias-2.c

int a[10] = {};
extern int b[10];
int off;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <offset>\n", argv[0]);
    return 1;
  }

  int off = atoi(argv[1]);
  b[off] = 1;
  a[off] = 2;
  if (b[off] != 2)
    abort();
  return 0;
}
