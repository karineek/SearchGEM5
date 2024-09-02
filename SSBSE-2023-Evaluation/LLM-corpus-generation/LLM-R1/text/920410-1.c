// Modification timestamp: 2023-08-14 13:25:44
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/920410-1.c
/* { dg-require-stack-size "40000 * 4 + 256" } */

main(){int d[40000];d[0]=0;exit(0);}
