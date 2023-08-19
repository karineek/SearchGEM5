
// Modification timestamp: 2023-08-10 16:19:34
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Benchmarks/Stanford/20000403-1.c

extern unsigned long aa[], bb[];

int seqgt (unsigned long a, unsigned short win, unsigned long b);

int seqgt2 (unsigned long a, unsigned short win, unsigned long b);

int main() {
  if (! seqgt (*aa, 0x1000, *bb) || ! seqgt2 (*aa, 0x1000, *bb))
    abort ();

  exit (0);
}

int seqgt (unsigned long a, unsigned short win, unsigned long b) {
  return (long) ((a + win) - b) > 0;
}

int seqgt2 (unsigned long a, unsigned short win, unsigned long b) {
  long l = ((a + win) - b);
  return l > 0;
}

unsigned long aa[] = { (1UL << (sizeof (long) * 8 - 1)) - 0xfff };
unsigned long bb[] = { (1UL << (sizeof (long) * 8 - 1)) - 0xfff };
