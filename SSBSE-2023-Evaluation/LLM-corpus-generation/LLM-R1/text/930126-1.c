// Modification timestamp: 2023-08-14 13:32:53
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/930126-1.c
struct s {
  unsigned long long a:8, b:32;
};

struct s
f(struct s x)
{
  x.b = 0xcdef1234;
  return x;
}

main()
{
  static struct s i;
  i.a = 12;
  i = f(i);
  if (i.a != 12 || i.b != 0xcdef1234)
    abort();
  exit(0);
}
