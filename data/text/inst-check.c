// Modification timestamp: 2023-08-14 14:28:58
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/inst-check.c
#include <stdarg.h>

f(m)
{
  int i,s=0;
  for(i=0;i<m;i++)
    s+=i;
  return s;
}

main()
{
  exit (0);
}
