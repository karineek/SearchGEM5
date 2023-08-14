// Modification timestamp: 2023-08-14 14:43:41
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr17252.c
/* PR 17252.  When a char * pointer P takes its own address, storing
   into *P changes P itself.  */

char *a;

main ()
{
  /* Make 'a' point to itself.  */
  a = (char *)&a;

  /* Change what 'a' is pointing to.  */
  a[0]++;

  /* If a's memory tag does not contain 'a' in its alias set, we will
     think that this predicate is superfluous and change it to
     'if (1)'.  */
  if (a == (char *)&a)
    abort ();

  return 0;
}
