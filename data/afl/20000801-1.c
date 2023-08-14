
// Modification timestamp: 2023-08-10 16:41:56
// Original Source: https://github.com/llvm/llvm-test-suite/blob/master/SingleSource/Benchmarks/Misc/20000801-1.c

extern void abort(void);
extern void exit(int);

void foo(char *bp, unsigned n)
{
  register char c;
  register char *ep = bp + n;
  register char *sp;

  while (bp < ep)
  {
    sp = bp + 3;
    c = *sp;
    *sp = *bp;
    *bp++ = c;
    sp = bp + 1;
    c = *sp;
    *sp = *bp;
    *bp++ = c;
    bp += 2;
  }
}

int main(int argc, char *argv[])
{
  int one = 1;

  if (argc != 2)
  {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int argValue = atoi(argv[1]);

  if (sizeof(int) != 4 * sizeof(char))
    exit(argValue);

  foo((char *)&one, sizeof(one));
  foo((char *)&one, sizeof(one));

  if (one != argValue)
    abort();

  exit(argValue);
}
