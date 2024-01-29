// Modification timestamp: 2023-08-14 13:26:09
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/920429-1.c
typedef unsigned char t;int i,j;
t*f(t*p){t c;c=*p++;i=((c&2)?1:0);j=(c&7)+1;return p;}
main(){t*p0="ab",*p1;p1=f(p0);if(p0+1!=p1)abort();exit(0);}
