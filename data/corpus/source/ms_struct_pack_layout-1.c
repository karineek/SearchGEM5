// Modification timestamp: 2023-08-14 17:29:31
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/ms_struct_pack_layout-1.c

#include <stdio.h>
#include <stdlib.h>

extern void abort ();

union u
{
  int a;
} __attribute__((__ms_struct__, __packed__));

struct s
{
  char c;
  union u u;
};

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  union u u1;
  u1.a = atoi(argv[1]);
  struct s s1;
  s1.c = u1.a;

  if (sizeof (struct s) != (sizeof (char) + sizeof (union u)))
    abort ();

  return 0;
}
