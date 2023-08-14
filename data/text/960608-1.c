// Modification timestamp: 2023-08-14 13:46:43
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/960608-1.c
typedef struct
{
  unsigned char a  : 2;
  unsigned char b  : 3;
  unsigned char c  : 1;
  unsigned char d  : 1;
  unsigned char e  : 1;
} a_struct;

foo (flags)
     a_struct *flags;
{
  return (flags->c != 0
	  || flags->d != 1
	  || flags->e != 1
	  || flags->a != 2
	  || flags->b != 3);
}

main ()
{
  a_struct flags;

  flags.c  = 0;
  flags.d  = 1;
  flags.e  = 1;
  flags.a  = 2;
  flags.b  = 3;

  if (foo (&flags) != 0)
    abort ();
  else
    exit (0);
}
