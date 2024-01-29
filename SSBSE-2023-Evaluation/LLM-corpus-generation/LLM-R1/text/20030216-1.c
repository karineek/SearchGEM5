// Modification timestamp: 2023-08-14 12:42:49
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20030216-1.c
/* This test requires constant propagation of loads and stores to be
   enabled.  This is only guaranteed at -O2 and higher.  Do not run
   at -O1.  */
/* { dg-skip-if "requires higher optimization" { *-*-* } "-O1" "" } */

void link_error (void);
const double one=1.0;
main ()
{
#ifdef __OPTIMIZE__
  if ((int) one != 1)
    link_error ();
#endif
  return 0;
}
