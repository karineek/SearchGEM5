// Modification timestamp: 2023-08-14 13:19:49
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20111227-1.c

extern void abort (void);

void __attribute__((noinline,noclone))
bar (int a)
{
  if (a != -1)
    abort ();
}

void __attribute__((noinline,noclone))
foo (short *a, int t)
{
  short r = *a;

  if (t)
    bar ((unsigned short) r);
  else
    bar ((signed short) r);
}

short v = -1;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  short v = atoi(argv[1]);
  foo (&v, 0);
  return 0;
}
