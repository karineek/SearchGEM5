// Modification timestamp: 2023-08-14 13:18:52
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20101011-1.c

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sigfpe(int signum __attribute__ ((unused))) {
  exit(0);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

#if defined(SIGNAL_SUPPRESS) || defined(__powerpc__) || defined(__PPC__) || defined(__ppc__) || defined(__POWERPC__) || defined(__ppc) || defined(__riscv) || defined(__SPU__) || defined(__sh__) || defined(__v850__) || defined(__MSP430__) || defined(__RL78__) || defined(__RX__) || defined(__aarch64__) || defined(__TMS320C6X__) || defined(__VISIUM__) || (defined(__mips__) && !defined(__linux__)) || (defined(__mips16) && defined(__linux__)) || defined(__MICROBLAZE__) || defined(__epiphany__) || (defined(__m68k__) && !defined(__linux__)) || defined(__CRIS__) || defined(__MMIX__) || defined(__arc__) || (defined(__arm__) && defined(__ARM_EABI__)) || defined(__nios2__) || defined(__nvptx__) || defined(__csky__) || defined(__moxie__) || defined(__or1k__) || defined(__pru__)
  signal(SIGFPE, sigfpe);
#endif

  int i;
  int j;
  int k;

  i = atoi(argv[1]);
  j = atoi(argv[2]);

  k = i / j;

  abort();
}
