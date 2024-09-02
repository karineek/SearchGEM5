// Modification timestamp: 2023-08-14 14:29:56
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/loop-10.c
/* Reduced from PR optimization/5076, PR optimization/2847 */

static int count = 0;

static void
inc (void)
{
  count++;
}

int
main (void)
{
  int iNbr = 1;
  int test = 0;
  while (test == 0)
    {
      inc ();
      if (iNbr == 0)
        break;
      else
        {
          inc ();
          iNbr--;
        }
      test = 1;
    }
  if (count != 2)
    abort ();
  return 0;
}
