// Modification timestamp: 2023-08-14 11:52:33
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20001013-1.c
struct x {
	int a, b;
} z = { -4028, 4096 };

int foo(struct x *p, int y)
{
  if ((y & 0xff) != y || -p->b >= p->a)
    return 1;
  return 0;
}

main()
{
  if (foo (&z, 10))
    abort ();
  exit (0);
}
