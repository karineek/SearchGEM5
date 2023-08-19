// Modification timestamp: 2023-08-14 13:18:29
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20100708-1.c

struct S
{
  double for_alignment;
  struct { int x, y, z; } a[16];
};

void f(int argc, char *argv[], struct S *s) __attribute__((noinline));

void f(int argc, char *argv[], struct S *s)
{
  unsigned int i;

  for (i = 0; i < 16; ++i)
    {
      s->a[i].x = atoi(argv[i+1]);
      s->a[i].y = atoi(argv[i+17]);
      s->a[i].z = atoi(argv[i+33]);
    }
}

int main (int argc, char *argv[])
{
  if (argc != 49) {
    printf("Usage: %s <value1> <value2> ... <value48>\n", argv[0]);
    return 1;
  }

  struct S s;
  f (argc, argv, &s);
  return 0;
}

//Note: //This conversion assumes that the command-line arguments supplied to the program are in the following format: `<value1> <value2> ... <value48>`.