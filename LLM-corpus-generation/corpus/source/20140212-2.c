// Modification timestamp: 2023-08-14 13:21:43
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20140212-2.c

#include <stdio.h>
#include <stdlib.h>

int f(unsigned short usVlanID) __attribute__((noinline,noclone));
int f(unsigned short usVlanID)
{
  unsigned int uiVlanID = 0xffffffff;
  int i;
  if ((unsigned short)0xffff != usVlanID)
    uiVlanID = (unsigned int)usVlanID;
  return uiVlanID;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  unsigned short usVlanID = atoi(argv[1]);
  int result = f(usVlanID);

  if (result != 0) {
    __builtin_abort();
  }
  return 0;
}
