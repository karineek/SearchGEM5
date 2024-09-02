// Modification timestamp: 2023-08-14 14:57:34
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr35163.c
extern void abort(void);

int main()
{
  signed char a = -30;
  signed char b = -31;
  #if(__SIZEOF_INT__ >= 4)
  if (a > (unsigned short)b)
#else
  if ((long) a > (unsigned short)b)
#endif
    abort ();
  return 0;
}
