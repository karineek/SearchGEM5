// Modification timestamp: 2023-08-14 14:51:16
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr28778.c
extern void abort(void);
typedef long GLint;
void aglChoosePixelFormat (const GLint *);

void
find (const int *alistp)
{
  const int *blist;
  int list[32];
  if (alistp)
    blist = alistp;
  else
    {
      list[3] = 42;
      blist = list;
    }
  aglChoosePixelFormat ((GLint *) blist);
}

void
aglChoosePixelFormat (const GLint * a)
{
  int *b = (int *) a;
  if (b[3] != 42)
    abort ();
}

int
main (void)
{
  find (0);
  return 0;
}
