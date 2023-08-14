// Modification timestamp: 2023-08-14 13:15:20
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20081117-1.c

extern void abort(void);

struct s {
  unsigned long long a:16;
  unsigned long long b:32;
  unsigned long long c:16;
};

__attribute__ ((noinline)) unsigned f(struct s s, unsigned i) {
  return s.b == i;
}

struct s s = {1, 0x87654321u, 2};

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  unsigned i = atoi(argv[1]);
  if (!f(s, i))
    abort();
  return 0;
}
