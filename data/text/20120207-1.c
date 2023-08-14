// Modification timestamp: 2023-08-14 13:20:08
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20120207-1.c
/* PR middle-end/51994 */
/* Testcase by Uros Bizjak <ubizjak@gmail.com> */

extern char *strcpy (char *, const char *);
extern void abort (void);

char __attribute__((noinline))
test (int a)
{
  char buf[16];
  char *output = buf;

  strcpy (&buf[0], "0123456789");

  output += a;
  output -= 1;

  return output[0];
}

int main ()
{
  if (test (2) != '1')
    abort ();

  return 0;
}
