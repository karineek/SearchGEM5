// Modification timestamp: 2023-08-14 14:51:16
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr28778.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
typedef long GLint;
void aglChoosePixelFormat(const GLint *);

void find(const int *alistp)
{
  const int *blist;
  int list[32];
  if (alistp)
    blist = alistp;
  else
  {
    int arg1 = 42;
    list[3] = arg1;
    blist = list;
  }
  aglChoosePixelFormat((GLint *) blist);
}

void aglChoosePixelFormat(const GLint *a)
{
  int *b = (int *)a;
  if (b[3] != 42)
    abort();
}

int main(int argc, char *argv[])
{
  find(NULL);
  return 0;
}
