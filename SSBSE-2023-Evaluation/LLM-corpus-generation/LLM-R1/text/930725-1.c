// Modification timestamp: 2023-08-14 13:35:46
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/930725-1.c
int v;

char *
g ()
{
  return "";
}

char *
f ()
{
  return (v == 0 ? g () : "abc");
}

main ()
{
  v = 1;
  if (!strcmp (f (), "abc"))
    exit (0);
  abort();
}
