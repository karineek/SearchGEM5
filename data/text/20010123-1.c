// Modification timestamp: 2023-08-14 11:57:14
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20010123-1.c
extern void abort ();
extern void exit (int);

struct s
{
    int value;
    char *string;
};

int main (void)
{
  int i;
  for (i = 0; i < 4; i++)
    {
      struct s *t = & (struct s) { 3, "hey there" };
      if (t->value != 3)
	abort();
      t->value = 4;
      if (t->value != 4)
	abort();
    }
  exit (0);
}
