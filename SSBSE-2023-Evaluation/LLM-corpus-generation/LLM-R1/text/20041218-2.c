// Modification timestamp: 2023-08-14 13:00:53
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20041218-2.c
extern void abort (void);

int test(int n)
{
  struct s { char b[n]; } __attribute__((packed));
  n++;
  return sizeof(struct s);
}

int main()
{
  if (test(123) != 123)
    abort ();
  return 0;
}
