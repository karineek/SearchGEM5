// Modification timestamp: 2023-08-14 13:29:50
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/920829-1.c
long long c=2863311530LL,c3=2863311530LL*3;
main(){if(c*3!=c3)abort();exit(0);}
