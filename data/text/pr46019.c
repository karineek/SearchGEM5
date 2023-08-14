// Modification timestamp: 2023-08-14 15:14:41
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr46019.c
/* PR middle-end/46019 */

extern void abort (void);

int
main (void)
{
  unsigned long long l = 0x40000000000ULL;
  int n;
  for (n = 0; n < 8; n++)
    if (l / (0x200000000ULL << n) != (0x200 >> n))
      abort ();
  return 0;
}
