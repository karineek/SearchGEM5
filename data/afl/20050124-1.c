// Modification timestamp: 2023-08-14 13:01:58
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20050124-1.c

extern void abort (void);

int foo(int i, int j) {
  int k = i + 1;

  if (j) {
    if (k > 0)
      k++;
    else if (k < 0)
      k--;
  }

  return k;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int arg1 = atoi(argv[1]);
  int arg2 = atoi(argv[2]);

  if (foo(arg1, arg2) != arg3) {
    abort();
  }
  return 0;
}

Please note that the variable `arg3` is missing because it is not specified in the original code where it should come from. Please replace `arg3` with the appropriate argument value when using the generated code.