// Modification timestamp: 2023-08-14 12:49:02
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20030920-1.c
extern void abort (void);

int main()
{
  int hicount = 0;
  unsigned char *c;
  char *str = "\x7f\xff";
  for (c = (unsigned char *)str; *c ; c++) {
    if (!(((unsigned int)(*c)) < 0x80)) hicount++;
  }
  if (hicount != 1)
    abort ();
  return 0;
}
