// Modification timestamp: 2023-08-14 14:06:47
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/bitfld-3.c

#include <stdio.h>
#include <stdlib.h>

struct s {
  unsigned long long u33: 33;
  unsigned long long u40: 40;
  unsigned long long u41: 41;
};

extern void exit (int);
extern void abort (void);

int main(int argc, char *argv[]) {
  struct s a = { atoi(argv[1]), atoi(argv[2]), atoi(argv[3]) };
  struct s b = { atoi(argv[4]), atoi(argv[5]), atoi(argv[6]) };
  struct s c = { atoi(argv[7]), atoi(argv[8]), atoi(argv[9]) };

  if (a.u33 * a.u33 != 0 || a.u33 * a.u40 != 0 || a.u40 * a.u33 != 0 || a.u40 * a.u40 != 0)
    abort();
  if (a.u33 * a.u41 != 0x10000000000ULL || a.u40 * a.u41 != 0x10000000000ULL
      || a.u41 * a.u33 != 0x10000000000ULL || a.u41 * a.u40 != 0x10000000000ULL
      || a.u41 * a.u41 != 0x10000000000ULL)
    abort();
  if (b.u33 + b.u33 != 0)
    abort();
  if (b.u33 + b.u40 != 0x200000000ULL || b.u33 + b.u41 != 0x200000000ULL
      || b.u40 + b.u33 != 0x200000000ULL || b.u40 + b.u40 != 0x200000000ULL
      || b.u40 + b.u41 != 0x200000000ULL || b.u41 + b.u33 != 0x200000000ULL
      || b.u41 + b.u40 != 0x200000000ULL || b.u41 + b.u41 != 0x200000000ULL)
    abort();
  if (a.u33 - b.u33 != 0x100100000ULL || a.u33 - b.u40 != 0xFF00100000ULL
      || a.u33 - b.u41 != 0x1FF00100000ULL || a.u40 - b.u33 != 0xFF00100000ULL
      || a.u40 - b.u40 != 0xFF00100000ULL || a.u40 - b.u41 != 0x1FF00100000ULL
      || a.u41 - b.u33 != 0x1FF00100000ULL || a.u41 - b.u40 != 0x1FF00100000ULL
      || a.u41 - b.u41 != 0x1FF00100000ULL)
    abort();
  if (++c.u33 != 0 || --c.u40 != 0xFFFFFFFFFFULL || c.u41-- != 0)
    abort();
  exit(0);
}
