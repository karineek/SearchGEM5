// Modification timestamp: 2023-08-14 13:25:54
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/920415-1.c
/* { dg-require-effective-target label_values } */
main(){__label__ l;void*x(){return&&l;}goto*x();abort();return;l:exit(0);}
