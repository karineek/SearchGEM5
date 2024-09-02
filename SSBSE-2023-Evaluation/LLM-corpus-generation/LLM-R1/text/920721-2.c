// Modification timestamp: 2023-08-14 13:28:43
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/920721-2.c
/* { dg-skip-if "requires alloca" { ! alloca } { "-O0" } { "" } } */
f(){}
main(){int n=2;double x[n];f();exit(0);}
