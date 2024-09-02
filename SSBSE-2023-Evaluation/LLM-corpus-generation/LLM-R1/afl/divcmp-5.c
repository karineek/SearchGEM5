// Modification timestamp: 2023-08-14 14:25:06
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/divcmp-5.c

extern void abort(void);

int always_one_1(int a)
{
  if (a / 100 >= -999999999)
    return 1;
  else
    return 0;
}

int always_one_2(int a)
{
  if (a / 100 < -999999999)
    return 0;
  else
    return 1;
}

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int a = atoi(argv[1]);

  if (always_one_1(a) != 1)
    abort();

  if (always_one_2(a) != 1)
    abort();

  return 0;
}
