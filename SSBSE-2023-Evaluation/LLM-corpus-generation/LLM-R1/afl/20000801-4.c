
// Modification timestamp: 2023-08-10 16:43:09
// Original Source: https://github.com/llvm/llvm-test-suite/blob/master/SingleSource/UnitTests/2002-08-01-7-StructReturn.c

/* Origin: PR c/128 from Martin Sebor <sebor@roguewave.com>, adapted
   as a testcase by Joseph Myers <jsm28@cam.ac.uk>.
*/
/* Character arrays initialized by a string literal must have
   uninitialized elements zeroed.  This isn't clear in the 1990
   standard, but was fixed in TC2 and C99; see DRs #060, #092.
*/
extern void abort (void);

int foo (void) {
  char s[2] = "";
  return 0 == s[1];
}

char *t;

int main (int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  {
    char s[] = argv[1];
    t = s;
  }
  if (foo ())
    exit (0);
  else
    abort ();
}
