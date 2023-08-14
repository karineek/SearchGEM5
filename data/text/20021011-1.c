// Modification timestamp: 2023-08-14 12:37:05
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20021011-1.c
/* PR opt/8165.  */

extern void abort (void);

char buf[64];

int
main (void)
{
  int i;

  __builtin_strcpy (buf, "mystring");
  if (__builtin_strcmp (buf, "mystring") != 0)
    abort ();

  for (i = 0; i < 16; ++i)
    {
      __builtin_strcpy (buf + i, "mystring");
      if (__builtin_strcmp (buf + i, "mystring") != 0)
	abort ();
    }

  return 0;
}
