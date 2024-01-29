// Modification timestamp: 2023-08-14 13:29:46
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/920812-1.c
typedef int t;
f(t y){switch(y){case 1:return 1;}return 0;}
main(){if(f((t)1)!=1)abort();exit(0);}
