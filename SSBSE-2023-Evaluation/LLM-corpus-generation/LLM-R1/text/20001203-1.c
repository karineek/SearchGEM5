// Modification timestamp: 2023-08-14 11:54:49
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20001203-1.c
/* Origin: PR c/410 from Jan Echternach
   <jan.echternach@informatik.uni-rostock.de>,
   adapted to a testcase by Joseph Myers <jsm28@cam.ac.uk>.
*/

extern void exit (int);

static void
foo (void)
{
  struct {
    long a;
    char b[1];
  } x = { 2, { 0 } };
}

int
main (void)
{
  int tmp;
  foo ();
  tmp = 1;
  exit (0);
}
