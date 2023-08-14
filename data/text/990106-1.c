// Modification timestamp: 2023-08-14 13:51:59
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/990106-1.c
foo(bufp)
char *bufp;
{
    int x = 80;
    return (*bufp++ = x ? 'a' : 'b');
}

main()
{
  char x;

  if (foo (&x) != 'a')
    abort ();

  exit (0);
}
