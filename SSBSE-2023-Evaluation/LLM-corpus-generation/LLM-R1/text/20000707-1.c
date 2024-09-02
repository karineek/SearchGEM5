
// Modification timestamp: 2023-08-10 16:38:18
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/MultiSource/Benchmarks/tramp3d-v4/tramp3d-v4.c

extern void abort(void);
extern void exit(int);

struct baz {
  int a, b, c;
};

void foo (int a, int b, int c) {
  if (a != 4)
    abort ();
}

void bar (struct baz x, int b, int c) {
  foo (x.b, b, c);
}

int main () {
  struct baz x = { 3, 4, 5 };
  bar (x, 1, 2);
  exit (0);
}
