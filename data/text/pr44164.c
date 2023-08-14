// Modification timestamp: 2023-08-14 15:12:36
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr44164.c
struct X {
    struct Y {
	struct YY {
	    struct Z {
		int i;
	    } c;
	} bb;
    } b;
} a;
int __attribute__((noinline, noclone))
foo (struct Z *p)
{
  int i = p->i;
  a.b = (struct Y){};
  return p->i + i;
}
extern void abort (void);
int main()
{
  a.b.bb.c.i = 1;
  if (foo (&a.b.bb.c) != 1)
    abort ();
  return 0;
}
