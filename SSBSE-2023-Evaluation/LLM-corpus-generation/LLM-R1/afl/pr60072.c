// Modification timestamp: 2023-08-14 15:37:31
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr60072.c

int c = 1;

__attribute__ ((optimize (1)))
static int *foo (int *p)
{
  return p;
}

int main(int argc, char *argv[]) {
  int *p = &c;
  *foo(p) = 2;
  return c - 2;
}
