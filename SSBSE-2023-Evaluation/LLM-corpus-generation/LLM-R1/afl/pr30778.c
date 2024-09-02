// Modification timestamp: 2023-08-14 14:53:14
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr30778.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern void *memset (void *, int, __SIZE_TYPE__);
extern void abort (void);

struct reg_stat {
  void *last_death;
  void *last_set;
  void *last_set_value;
  int   last_set_label;
  char  last_set_sign_bit_copies;
  int   last_set_mode : 8;
  char  last_set_invalid;
  char sign_bit_copies;
  long nonzero_bits;
};

static struct reg_stat *reg_stat;

void __attribute__((noinline))
init_reg_last (void)
{
  memset (reg_stat, 0, __builtin_offsetof (struct reg_stat, sign_bit_copies));
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    int value = atoi(argv[1]);

    struct reg_stat r;

    reg_stat = &r;
    r.nonzero_bits = value;
    init_reg_last ();
    if (r.nonzero_bits != value)
        abort ();

    return 0;
}
