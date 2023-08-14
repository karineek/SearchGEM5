// Modification timestamp: 2023-08-14 13:28:35
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/920711-1.c
/* { dg-options "-fwrapv" } */

extern void abort (void);
extern void exit (int);

int f(long a){return (--a > 0);}
int main(){if(f(0x80000000L)==0)abort();exit(0);}
