// Modification timestamp: 2023-08-14 13:59:09
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/alias-access-path-1.c
/* Test that variable
     int val;
   may hold value of tyope "struct c" which has same size.
   This is valid in GIMPLE memory model.  */

struct a {int val;} a={1},a2;
struct b {struct a a;};
int val;
struct c {struct b b;} *cptr=(void *)&val;

int
main(void)
{
  cptr->b.a=a;
  val = 2;
  a2=cptr->b.a;
  if (a2.val == a.val)
    __builtin_abort ();
}
