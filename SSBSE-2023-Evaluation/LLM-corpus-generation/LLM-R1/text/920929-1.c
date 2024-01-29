// Modification timestamp: 2023-08-14 13:30:17
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/920929-1.c
/* { dg-skip-if "requires alloca" { ! alloca } { "-O0" } { "" } } */
/* REPRODUCED:RUN:SIGNAL MACHINE:sparc OPTIONS: */
f(int n)
{
int i;
double v[n];
for(i=0;i<n;i++)
v[i]=0;
}
main()
{
f(100);
exit(0);
}
