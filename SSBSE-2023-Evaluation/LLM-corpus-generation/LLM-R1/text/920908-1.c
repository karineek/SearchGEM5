// Modification timestamp: 2023-08-14 13:29:57
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/920908-1.c
/* REPRODUCED:RUN:SIGNAL MACHINE:mips OPTIONS: */

#include <stdarg.h>

typedef struct{int A;}T;

T f(int x,...)
{
va_list ap;
T X;
va_start(ap,x);
X=va_arg(ap,T);
if(X.A!=10)abort();
X=va_arg(ap,T);
if(X.A!=20)abort();
va_end(ap);
return X;
}

main()
{
T X,Y;
int i;
X.A=10;
Y.A=20;
f(2,X,Y);
exit(0);
}
