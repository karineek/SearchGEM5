// Modification timestamp: 2023-08-14 16:14:45
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/strct-pack-4.c

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  unsigned char a __attribute__((packed));
  unsigned short b __attribute__((packed));
} three_char_t;

unsigned char my_set_a (void) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }
}

unsigned short my_set_b (void) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  three_char_t three_char;

  three_char.a = my_set_a (argv[1][0]);
  three_char.b = my_set_b (atoi(argv[1]));

  if (three_char.a != argv[2][0] || three_char.b != atoi(argv[3]))
    abort ();

  exit (0);
}

