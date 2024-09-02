// Modification timestamp: 2023-08-14 11:55:46
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20010114-1.c

extern void abort(void);
extern void exit(int);

int main(int argc, char *argv[]) {
  int array1[1] = { atoi(argv[1]) };
  int array2[2][1] = { { atoi(argv[2]) }, { atoi(argv[3]) } };

  if (array1[0] != 1)
    abort();

  exit(0);
}
