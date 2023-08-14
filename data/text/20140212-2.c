// Modification timestamp: 2023-08-14 13:21:43
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20140212-2.c
/* This used to fail as we would convert f into just return (unsigned int)usVlanID
   which is wrong. */

int f(unsigned short usVlanID) __attribute__((noinline,noclone));
int f(unsigned short usVlanID)
{
  unsigned int uiVlanID = 0xffffffff;
  int i;
  if ((unsigned short)0xffff != usVlanID)
    uiVlanID = (unsigned int)usVlanID;
  return uiVlanID;
}

int main(void)
{
  if (f(1) != 1)
    __builtin_abort ();
  if (f(0xffff) != -1)
    __builtin_abort ();
  return 0;
}
