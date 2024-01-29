// Modification timestamp: 2023-08-14 12:15:39
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20020418-1.c
/* ifcvt accidentally deletes a referenced label while generating
   conditional traps on machines having such patterns */

struct foo { int a; };

void gcc_crash(struct foo *p)
{
	if (__builtin_expect(p->a < 52, 0))
		__builtin_trap();
 top:
	p->a++;
	if (p->a >= 62)
		goto top;
}

int main(void)
{
	struct foo x;

	x.a = 53;
	gcc_crash(&x);

	exit (0);
}
