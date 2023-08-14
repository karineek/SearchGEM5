// Modification timestamp: 2023-08-14 13:46:16
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/960419-2.c
#define SIZE 8

main()
{
  int a[SIZE] = {1};
  int i;

  for (i = 1; i < SIZE; i++)
    if (a[i] != 0)
      abort();

  exit (0);
}
