// Modification timestamp: 2023-08-14 12:46:22
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20030626-1.c
char buf[10];

extern void abort (void);
extern int sprintf (char*, const char*, ...);

int main()
{
  int l = sprintf (buf, "foo\0bar");
  if (l != 3)
    abort ();
  return 0;
}
