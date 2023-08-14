// Modification timestamp: 2023-08-14 12:48:10
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20030828-2.c
struct rtx_def
{
  int code;
};

main()
{
  int tmp[2];
  struct rtx_def *r, s;
  int *p, *q;

  /* The alias analyzer was creating the same memory tag for r, p and q
     because 'struct rtx_def *' is type-compatible with 'int *'.  However,
     the alias set of 'int[2]' is not the same as 'int *', so variable
     'tmp' was deemed not aliased with anything.  */
  r = &s;
  r->code = 39;

  /* If 'r' wasn't declared, then q and tmp would have had the same memory
     tag.  */
  p = tmp;
  q = p + 1;
  *q = 0;
  tmp[1] = 39;
  if (*q != 39)
    abort ();
  exit (0);
}
