// Modification timestamp: 2023-08-14 14:57:34
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr35163.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

int main(int argc, char *argv[]) {
  signed char a = atoi(argv[1]);
  signed char b = atoi(argv[2]);
  #if(__SIZEOF_INT__ >= 4)
  if (a > (unsigned short)b)
#else
  if ((long) a > (unsigned short)b)
#endif
    abort ();
  return 0;
}
