// Modification timestamp: 2023-08-14 12:12:03
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20020328-1.c
int b = 0;

func () { }

void
testit(int x)
{
  if (x != 20)
    abort ();
}

int
main()

{
  int a = 0;

  if (b)
    func();

  /* simplify_and_const_int would incorrectly omit the mask in
     the line below.  */
  testit ((a + 23) & 0xfffffffc);
  exit (0);
}
