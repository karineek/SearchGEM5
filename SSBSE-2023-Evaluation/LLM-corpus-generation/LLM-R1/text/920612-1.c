// Modification timestamp: 2023-08-14 13:28:04
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/920612-1.c
/* { dg-options "-fwrapv" } */

extern void abort (void);
extern void exit (int);

int f(j)int j;{return++j>0;}
int main(){if(f((~0U)>>1))abort();exit(0);}
