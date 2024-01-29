// Modification timestamp: 2023-08-14 12:46:27
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20030626-2.c
char buf[40];

extern int sprintf (char*, const char*, ...);
extern void abort (void);

int main()
{
  int i = 0;
  int l = sprintf (buf, "%s", i++ ? "string" : "other string");
  if (l != sizeof ("other string") - 1 || i != 1)
    abort ();
  return 0;
}
