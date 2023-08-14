// Modification timestamp: 2023-08-14 12:07:30
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20011223-1.c
/* Origin: Joseph Myers <jsm28@cam.ac.uk>.  */
/* Case labels in a switch statement are converted to the promoted
   type of the controlling expression, not an unpromoted version.
   Reported as PR c/2454 by
   Andreas Krakowczyk <Andreas.Krakowczyk@fujitsu-siemens.com>.  */

extern void exit (int);
extern void abort (void);

static int i;

int
main (void)
{
  i = -1;
  switch ((signed char) i) {
  case 255:
    abort ();
  default:
    exit (0);
  }
}
