// Modification timestamp: 2023-08-14 14:34:12
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/mayalias-2.c
typedef struct __attribute__((__may_alias__)) { short x; } test;

int f() {
  int a=10;
  test *p=(test *)&a;
  p->x = 1;
  return a;
}

int main() {
  if (f() == 10)
    __builtin_abort();
  return 0;
}
