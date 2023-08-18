// Modification timestamp: 2023-08-10 16:19:34
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Benchmarks/Stanford/20000403-1.c
#include <stddef.h>
#include <stdio.h>
#include <string.h>

extern unsigned long aa[], bb[];

int seqgt (unsigned long a, unsigned short win, unsigned long b);

int seqgt2 (unsigned long a, unsigned short win, unsigned long b);

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <aa_0> <bb_0>\n", argv[0]);
    return 1;
  }

  unsigned long aa[] = { strtoul(argv[1], NULL, 10) };
  unsigned long bb[] = { strtoul(argv[2], NULL, 10) };

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
