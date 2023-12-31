// Modification timestamp: 2023-08-14 14:45:17
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr20621-1.c
/* { dg-require-stack-size "0x10000" } */

/* When generating o32 MIPS PIC, main's $gp save slot was out of range
   of a single load instruction.  */
struct big { int i[sizeof (int) >= 4 && sizeof (void *) >= 4 ? 0x4000 : 4]; };
struct big gb;
int foo (struct big b, int x) { return b.i[x]; }
int main (void) { return foo (gb, 0) + foo (gb, 1); }
