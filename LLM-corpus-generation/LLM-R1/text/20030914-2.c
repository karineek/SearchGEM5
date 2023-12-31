// Modification timestamp: 2023-08-14 12:48:45
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20030914-2.c
/* On IRIX 6, PA is passed partially in registers and partially on the
   stack.  We therefore have two potential uses of pretend_args_size:
   one for the partial argument and one for the varargs save area.
   Make sure that these uses don't conflict.  */

struct s { int i[18]; };

int f (struct s pa, int pb, ...)
{
  return pb;
}

struct s gs;

int main ()
{
  if (f (gs, 0x1234) != 0x1234)
    abort ();

  exit (0);
}
