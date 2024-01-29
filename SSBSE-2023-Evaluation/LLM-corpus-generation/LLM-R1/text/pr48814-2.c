// Modification timestamp: 2023-08-14 15:17:07
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr48814-2.c
extern void abort (void);

int arr[] = {1,2,3,4};
int count = 0;

int
incr (void)
{
  return ++count;
}

int main()
{
  arr[count++] = incr ();
  if (count != 2 || arr[count] != 3)
    abort ();
  return 0;
}
