// Modification timestamp: 2023-08-14 12:43:03
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20030221-1.c
/* PR optimization/8613 */
/* Contributed by Glen Nakamura */

extern void abort (void);

int main (void)
{
  char buf[16] = "1234567890";
  char *p = buf;

  *p++ = (char) __builtin_strlen (buf);

  if ((buf[0] != 10) || (p - buf != 1))
    abort ();

  return 0;
}
