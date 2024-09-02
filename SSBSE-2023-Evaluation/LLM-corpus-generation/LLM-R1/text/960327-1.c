// Modification timestamp: 2023-08-14 13:45:46
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/960327-1.c
#include <stdio.h>
g ()
{
  return '\n';
}

f ()
{
  char s[] = "abcedfg012345";
  char *sp = s + 12;

  switch (g ())
    {
      case '\n':
        break;
    }

  while (*--sp == '0')
    ;
  sprintf (sp + 1, "X");

  if (s[12] != 'X')
    abort ();
}

main ()
{
  f ();
  exit (0);
}
