// Modification timestamp: 2023-08-14 13:28:40
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/920721-1.c
long f(short a,short b){return (long)a/b;}
main(){if(f(-32768,-1)!=32768L)abort();else exit(0);}
