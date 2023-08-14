// Modification timestamp: 2023-08-14 17:23:41
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2008-07-13-InlineSetjmp.c
// PR2486

#include <setjmp.h>
#include <stdio.h>
jmp_buf g;
static int a() {longjmp(g,1);}
static void b(int* x) {if (setjmp(g))return;*x = 10;a();}
int main() {int a = 1; b(&a); printf("%d\n", a); return 0;}

