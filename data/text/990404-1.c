// Modification timestamp: 2023-08-14 13:54:53
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/990404-1.c

int x[10] = { 0,1,2,3,4,5,6,7,8,9};

int
main()
{
  int niterations = 0, i;

  for (;;) {
    int i, mi, max;
    max = 0;
    for (i = 0; i < 10 ; i++) {
      if (x[i] > max) {
	max = x[i];
	mi = i;
      }
    }
    if (max == 0)
      break;
    x[mi] = 0;
    niterations++;
    if (niterations > 10)
      abort ();
  }

  exit (0);
}
