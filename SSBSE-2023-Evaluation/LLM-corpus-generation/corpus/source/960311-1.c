// Modification timestamp: 2023-08-14 13:44:51
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/960311-1.c

#include <stdio.h>
#include <stdlib.h>

#ifdef DEBUG
#define abort() printf ("error, line %d\n", __LINE__)
#endif

int count;

void a1() { ++count; }

void b(unsigned char data) {
  if (data & 0x80) a1();
  data <<= 1;

  if (data & 0x80) a1();
  data <<= 1;

  if (data & 0x80) a1();
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  count = 0;
  b(atoi(argv[1]));
  if (count != 0)
    abort();

  count = 0;
  b(0x80);
  if (count != 1)
    abort();

  count = 0;
  b(0x40);
  if (count != 1)
    abort();

  count = 0;
  b(0x20);
  if (count != 1)
    abort();

  count = 0;
  b(0xc0);
  if (count != 2)
    abort();

  count = 0;
  b(0xa0);
  if (count != 2)
    abort();

  count = 0;
  b(0x60);
  if (count != 2)
    abort();

  count = 0;
  b(0xe0);
  if (count != 3)
    abort();

#ifdef DEBUG
  printf("Done.\n");
#endif
  return 0;
}
