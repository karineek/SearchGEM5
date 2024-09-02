// Modification timestamp: 2023-08-14 13:25:59
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/920428-1.c
x(const char*s){char a[1];const char*ss=s;a[*s++]|=1;return(int)ss+1==(int)s;}
main(){if(x("")!=1)abort();exit(0);}
