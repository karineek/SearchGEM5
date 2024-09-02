// Modification timestamp: 2023-08-04 14:11:52
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00108.c

int foo(void);
int foo(void);
#define FOO 0

int main() {
  return FOO;
}
