// Modification timestamp: 2023-08-14 12:35:58
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20020805-1.c
/* This testcase was miscompiled on IA-32, because fold-const
   assumed associate_trees is always done on PLUS_EXPR.  */

extern void abort (void);
extern void exit (int);

void check (unsigned int m)
{
  if (m != (unsigned int) -1)
    abort ();
}

unsigned int n = 1;

int main (void)
{
  unsigned int m;
  m = (1 | (2 - n)) | (-n);
  check (m);
  exit (0);
}
