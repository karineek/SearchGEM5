// Modification timestamp: 2023-08-14 12:05:27
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20010925-1.c
extern void exit(int);
extern void abort (void);

extern void * memcpy (void *, const void *, __SIZE_TYPE__);
int foo (void *, void *, unsigned int c);

int src[10];
int dst[10];

int main()
{
   if (foo (dst, src, 10) != 0)
     abort();
   exit(0);
}

int foo (void *a, void *b, unsigned int c)
{
  if (c == 0)
    return 1;

  memcpy (a, b, c);
  return 0;
}
