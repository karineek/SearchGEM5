
// Modification timestamp: 2023-08-10 16:39:32
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/MultiSource/Benchmarks/tramp3d-v4/tramp3d-v4.c

typedef struct trio { int a, b, c; } trio;

int
bar (int i, trio t)
{
  if (t.a == t.b || t.a == t.c)
    abort ();
}

int
foo (trio t, int i)
{
  return bar (i, t);
}

int main()
{
  trio t = { 1, 2, 3 };

  foo (t, 4);
  exit (0);
}
