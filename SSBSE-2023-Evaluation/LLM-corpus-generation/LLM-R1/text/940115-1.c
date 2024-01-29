// Modification timestamp: 2023-08-14 13:40:15
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/940115-1.c
f (cp, end)
     char *cp;
     char *end;
{
  return (cp < end);
}

main ()
{
  if (! f ((char *) 0, (char *) 1))
    abort();
  exit (0);
}
