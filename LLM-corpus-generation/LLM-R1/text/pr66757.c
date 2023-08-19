// Modification timestamp: 2023-08-14 15:45:04
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr66757.c
/* PR tree-optimization/66757 */
/* Testcase by Zhendong Su <su@cs.ucdavis.edu> */

int a, b;

int
main (void)
{
  unsigned int t = (unsigned char) (~b);

  if ((t ^ 1) / 255)
    __builtin_abort ();

  return 0;
}
