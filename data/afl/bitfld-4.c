// Modification timestamp: 2023-08-14 14:06:50
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/bitfld-4.c

extern void abort(void);

struct s {
  int a:12, b:20;
};

struct s x = { -123, -456 };

int main(int argc, char *argv[]) {
  if (x.a != atoi(argv[1]) || x.b != atoi(argv[2])) {
    abort();
  }
  return 0;
}
