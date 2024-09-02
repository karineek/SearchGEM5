// Modification timestamp: 2023-08-14 12:06:54
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20011121-1.c
struct s
{
  int i[18];
  char f;
  char b[2];
};

struct s s1;

int
main()
{
  struct s s2;
  s2.b[0] = 100;
  __builtin_memcpy(&s2, &s1, ((unsigned int) &((struct s *)0)->b));
  if (s2.b[0] != 100)
    abort();
  exit(0);
}
