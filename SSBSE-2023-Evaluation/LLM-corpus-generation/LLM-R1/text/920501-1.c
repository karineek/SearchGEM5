// Modification timestamp: 2023-08-14 13:26:14
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/920501-1.c
/* { dg-require-effective-target untyped_assembly } */
int s[2];
x(){if(!s[0]){s[1+s[1]]=s[1];return 1;}}
main(){s[0]=s[1]=0;if(x(0)!=1)abort();exit(0);}
